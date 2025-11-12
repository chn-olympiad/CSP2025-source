#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100010
#define inf 0x3f3f3f

ll k,n;
ll l1,l2,l3,ans=0;
struct student{
    ll a1,a2,a3,m,p,cf;	
}t[MAXN];

bool cmp(student &a,student &b){
	return a.cf>b.cf;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>k;
	for(int l=1;l<=k;l++){
		cin>>n;
		ans=0;
		l1=0;
		l2=0;
		l3=0;
		memset(t,0,sizeof(t));
		for(int i=1;i<=n;i++){
			cin>>t[i].a1>>t[i].a2>>t[i].a3;
			if(t[i].a1>=t[i].a2&&t[i].a1>=t[i].a3){
				    t[i].m=t[i].a1;
				    t[i].p=1;
				if(t[i].a2>=t[i].a3){
					t[i].cf=t[i].a1-t[i].a2;
				}else{
					t[i].cf=t[i].a1-t[i].a3;
				}
			}
			if(t[i].a2>=t[i].a1&&t[i].a2>=t[i].a3){
				t[i].m=t[i].a2;
				t[i].p=2;
				if(t[i].a1>=t[i].a3){
					t[i].cf=t[i].a2-t[i].a1;
				}else{
					t[i].cf=t[i].a2-t[i].a3;
				}
			}
			if(t[i].a3>=t[i].a1&&t[i].a3>=t[i].a2){
				t[i].m=t[i].a3;
				t[i].p=3;
				if(t[i].a1>=t[i].a2){
					t[i].cf=t[i].a3-t[i].a1;
				}else{
					t[i].cf=t[i].a3-t[i].a2;
				}
			}
		}
		sort(t+1,t+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(t[i].p==1){
				l1++;
				if(l1>n/2){
				    ans+=t[i].m-t[i].cf;
				    continue;	
				}
			}
			if(t[i].p==2){
				l2++;
				if(l2>n/2){
					ans+=t[i].m-t[i].cf;
				    continue;	
				}
			}
			if(t[i].p==3){
				l3++;
				if(l3>n/2){
					ans+=t[i].m-t[i].cf;
				    continue;
				}
			}
			ans+=t[i].m;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
