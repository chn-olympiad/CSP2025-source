#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn =1e6+10;
ll t,n,ans,de1,flog1=true,de2,flog2=true,de3,flog3=true;
struct men{
	ll a,b,c;
}mem[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int zx=1;zx<=t;zx++){
  ans=0
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>mem[i].a>>mem[i].b>>mem[i].c;
		}
		for(int i=1;i<=n;i++){
			if(mem[i].a>=mem[i].b&&mem[i].a>=mem[i].b&&flog1){
				ans+=mem[i].a;de1++;
				if(de1>=n/2){
					flog1=false;
				}
			}else if(mem[i].b>=mem[i].a&&mem[i].b>=mem[i].c&&flog2){
				ans+=mem[i].b;de2++;
				if(de2>=n/2){
					flog2=false;
				}
			}else if(mem[i].c>=mem[i].a&&mem[i].c>=mem[i].b&&flog3){
				ans+=mem[i].a;de3++;
				if(de3>=n/2){
					flog3=false;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

