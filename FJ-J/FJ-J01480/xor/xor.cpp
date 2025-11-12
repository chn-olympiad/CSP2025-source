#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,num;
}c[500005];
bool cmp(node x,node y){
	if(x.num!=y.num){
	return x.num<y.num;
	}else{
		return x.id<y.id;
	}
}
int cnt,f=1,n,k,v,a[500005],b[500005],q,ch[500005];
int fi1(int l,int r){
	while(l<r){
		int mid=(l+r)/2;
	//	cout<<c[mid].num<<endl;
		if(c[mid].num<q){
			l=mid+1;
		}else{
			r=mid;
			
		}
	//	cout<<l<<r<<endl;
	}
	
	return l;
}
int fi2(int l,int r){
	while(l<r){
		int mid=(l+r+1)/2;
		if(c[mid].num==q){
			l=mid;
		}else if(c[mid].num>q){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return l;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1];
		b[i]^=a[i];
		c[i].num=b[i];
		c[i].id=i;
	}
	
	if(n<=1005){
		for(int i=1;i<=n;i++){
		ch[i]=cnt;
			for(int j=f;j<=i;j++){
				int p=(b[i]^b[j-1]);
				//cout<<p<<endl;
				if(p==k){
				cnt++;
			//cout<<i<<" "<<j<<endl;
				f=i+1;
				//cout<<q<<  p<<endl;
				break;
				}
			}
			
		}
		cout<<cnt<<endl;
		cnt=0;
		f=1;
	}else{
		
		sort(c+1,c+1+n,cmp);
		f=1;
		for(int i=1;i<=n;i++){
			int p=k;
			q=b[i]^p;
			if(q==0 and f==1){
				cnt++;
				f=i+1;
				continue;
			}
			//cout<<i<<" "<<f<<" "<<q<<" ";
			int l=fi1(1,n);
		//	cout<<c[l].id<<" ";
			int r=fi2(1,n);
			//cout<<c[r].id<<" "<<cnt<<endl;
			if(c[l].num!=k){
				continue;
			}
			if(f<=c[l].id or c[r].id<=i){
				cnt++;
			f=i+1;
		//	cout<<cnt<<endl;
			}
			
			
		}	
		cout<<cnt;
	}
	
	return 0;
}
