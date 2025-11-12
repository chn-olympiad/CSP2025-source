#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1005055],b[100055],cnt;
struct abc{
	long long int l,r,s;
}c[1994322];
bool cmp(abc x,abc y){
	if(x.l==y.l) return x.r<y.r;
	else return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
		b[1]=a[1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[++cnt].s=(b[j]^b[i-1]);
			c[cnt].l=i;
			c[cnt].r=j;
			if(i==1){
				c[cnt].s=b[j];
			}
			if(c[cnt].s!=k){
				cnt--;
			}
		}
	}
	//sort(c+1,c+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
	//	cout<<c[i].l<<' '<<c[i].r<<' '<<c[i].s<<endl;
	}
	long long ans=0;
	for(int j=0;j<=cnt;j++){
		while(c[j].l==c[j+1].l){
			j++;
			if(j>cnt) break;
		}
		long long i=j+1,s=0;
		for(;i<=cnt;){
		//	cout<<i<<' ';
			//cout<<c[i].l<<' '<<c[i].r<<endl;
			long long d=c[i].r+1;
			s++;
			i++;
			while(c[i].l<d){
				i++;
				if(i>cnt) break;
			}
		}
	//	cout<<"\n\n\n\n";
		ans=max(ans,s);
	}
	cout<<ans;
	return 0;
}