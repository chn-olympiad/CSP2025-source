#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define ll long long

ll t;
ll n,ans;
struct pers{
	ll a,b,c;
};
pers p[N],np[N];
bool cmp(pers a,pers b){
	return a.a>b.a;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		if(n==2){
			ll flag,fp,cmaxn=0;
			if(cmaxn<max(p[1].a,p[2].a)){
				cmaxn=max(p[1].a,p[2].a);
				flag=1;
				if(p[1].a>p[2].a) fp=2;
				else fp=1;
			}
			if(cmaxn<max(p[1].b,p[2].b)){
				cmaxn=max(p[1].b,p[2].b);
				flag=2;
				if(p[1].b>p[2].b) fp=2;
				else fp=1;
			}
			if(cmaxn<max(p[1].c,p[2].c)){
				cmaxn=max(p[1].c,p[2].c);
				flag=3;
				if(p[1].c>p[2].c) fp=2;
				else fp=1;
			}
			ans+=cmaxn;
			if(flag==1){
				ans+=max(p[fp].b,p[fp].c);
			}
			if(flag==2){
				ans+=max(p[fp].a,p[fp].c);
			}
			if(flag==3){
				ans+=max(p[fp].c,p[fp].a);
			}
			cout<<ans<<endl;
		}
		else{
			sort(p+1,p+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=p[i].a;
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
