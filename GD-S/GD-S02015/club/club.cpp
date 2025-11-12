#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
struct tt{
	int a,b,c;
}a[N];
int t,ans,n,f[66],ans1,ans2;
bool cmp1(tt a,tt b){//a>b;
	if(a.a==b.a)return a.b>b.b;
	else return a.a>b.a;
}
bool cmp2(tt a,tt b){//b>a;
	if(a.b==b.b)return a.a>b.a;
	else return a.b>b.b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int p1=0,p2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0)p1=1;
			if(a[i].c!=0)p2=1;
		}
		if(p1==0&&p2==0){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++)ans+=a[i].a;
			cout<<ans<<"\n";
		}
		else if(p2==0){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n;i++){
				if(a[i].a>a[i].b||f[1]<n/2){
					ans1+=a[i].a;
					f[1]++;
				}
				else {
					f[2]++;
					ans1+=a[i].b;
				}
			}
			memset(f,0,sizeof(f));
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(a[i].b>a[i].a||f[2]<n/2){
					ans2+=a[i].a;
					f[1]++;
				}
				else {
					f[2]++;
					ans2+=a[i].b;
				}
			}
			cout<<ans1<<"\n"<<ans2;
		}
	}
	return 0;
}

