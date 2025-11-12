#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],ans,k,l;
bool f=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0,k=0,l=0;
		f=0;
		memset(a,sizeof(a),0);
		memset(b,sizeof(b),0);
		memset(c,sizeof(c),0);
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]==0 && c[i]==0) f=1;
		}
		if(f){
			sort(a+1,a+n+1);
			for(int i=n;i>n/2;i--) ans+=a[i];
			cout<<ans<<endl;
		}else{
			int max1=max(max(a[1],b[1]),c[1]),maxn=max(min(a[1],b[1]),c[1]);
			int max2=max(max(a[2],b[2]),c[2]),maxm=max(min(a[2],b[2]),c[2]);
			if(max1==a[1]) k=1;
			if(max1==b[1]) k=2;
			if(max1==c[1]) k=3;
			if(max2==a[2]) l=1;
			if(max2==b[2]) l=2;
			if(max2==c[2]) l=3;
			if(k!=l) ans=max1+max2;
			else ans=max(max1+maxm,max2+maxn);
			cout<<ans<<endl;
		}
	}
	return 0;
}
