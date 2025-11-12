#include<bits/stdc++.h>

using namespace std;
const int N=1e5+7;
int t,cnt1,cnt2,cnt3,n,a[N],b[N],c[N],ans;
struct node{
	int f,s,t;
}k[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt1=0;
		cnt2=0;
		cnt3=0;
		ans=0;
		for(int i = 1 ; i <= n ; i++){
			cin>>k[i].f>>k[i].s>>k[i].t;
		}
		for(int i = 1 ; i <= n ; i++){
			ans+=max({k[i].f,k[i].s,k[i].t});
			if(max({k[i].f,k[i].s,k[i].t})==k[i].f){
				cnt1++;
				a[cnt1]=k[i].f-max(k[i].s,k[i].t);
			}
			else if(max({k[i].f,k[i].s,k[i].t})==k[i].s){
				cnt2++;
				b[cnt2]=k[i].s-max(k[i].f,k[i].t);
			}
			else{
				cnt3++;
				c[cnt3]=k[i].t-max(k[i].s,k[i].f);
			}
		}
		if(cnt1>n/2){
			sort(a+1,a+cnt1+1);
			for(int i = 1 ; i <= cnt1-n/2 ; i++){
				ans-=a[i]; 
			}
		}
		else if(cnt2>n/2){ 
			sort(b+1,b+cnt2+1);
			for(int i = 1 ; i <= cnt2-n/2 ; i++){
				ans-=b[i]; 
			}
		}
		else if(cnt3>n/2){ 
			sort(c+1,c+cnt3+1);
			for(int i = 1 ; i <= cnt3-n/2 ; i++){
				ans-=c[i]; 
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
