#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
ll T,n,a[N][4],choose[N],answer;
ll number[4];
ll b[N],cnt;
void CLEAR(){
	cnt=0;
	number[1]=number[2]=number[3]=0;
	answer=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				cin>>a[i][j];
			}
			ll maxx=max(a[i][1],max(a[i][2],a[i][3]));
			for(ll j=1;j<=3;j++){
				if(a[i][j]==maxx){
					choose[i]=j;
					answer+=maxx;
					number[j]++;
					break;
				}
			}
		}
		ll special;
		if(number[1]>n/2)special=1;
		else if(number[2]>n/2)special=2;
		else if(number[3]>n/2)special=3;
		else special=0;
		if(special==0){
			cout<<answer<<endl;
			CLEAR();
			continue;
		}
		for(ll i=1;i<=n;i++){
			if(choose[i]==special){
				ll tmp=0;
				for(ll j=1;j<=3;j++){
					if(j!=special){
						tmp=max(tmp,a[i][j]);
					}
				}
				b[++cnt]=-a[i][special]+tmp;
			}
		}
		sort(b+1,b+1+cnt,greater<ll>());
		for(ll i=1;i<=number[special]-n/2;i++){
			answer+=b[i];
		}
		cout<<answer<<endl;
		CLEAR();
	}
	return 0;
}
