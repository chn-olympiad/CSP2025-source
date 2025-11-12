#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],sum,cnt;
struct node{
	int x,y;
}aa[500006];
bool cmp(node a,node b){
	return a.y-a.x>b.y-b.x;
}
bool yes(int l1,int r1,int l2,int r2){
	if(l2>r1||l1>r2){
		return true;
		
	}else{
		for(int i=min(l1,l2);i<=max(r1,r2);i++){
			if(l1<=i&&r1>=i&&l2<=i&&r2>=i)return false;
		} 
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int kk=i;kk<=j;kk++){
				sum=a[kk]^sum;
			}
			if(sum==k){
				aa[++cnt].x=i;
				aa[cnt].y=j;	
			//	cout<<aa[i].x<<" "<<aa[i].y<<endl;;
			}
			sum=0;
		}
	}
//	cout<<endl;
	sort(aa+1,aa+n+1,cmp);
/*	for(int i=1;i<=cnt;i++){
		cout<<aa[i].x<<" "<<aa[i].y<<endl;
	}*/
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(!yes(aa[i].x,aa[i].y,aa[j].x,aa[j].y)){
			//	cout<<aa[i].x<<" "<<aa[i].y<<" "<<aa[j].x<<" "<<aa[j].y<<endl;
				aa[i].x=-1;aa[i].y=-1;
				continue;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
//cout<<aa[i].x<<" "<<aa[i].y<<endl;;
		if(aa[i].x==-1)continue;
		if(aa[i].x==0&&aa[i].y==0)continue;
		else{
			ans++;
		}
	}
	cout<<ans;
	return 0; 
} 
