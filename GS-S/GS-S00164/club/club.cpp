#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10;
LL a1[maxn],a2[maxn],a3[maxn];
LL b[maxn];
LL T,n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int k=n/2;
		int sum=0;
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			int dis=max(max(a1[i],a2[i]),a3[i]);
			b[i]=dis;	
		}
		sort(b+1,b+n+1);
		int cnt=0;
		for(int i=n;i>=1;i--){
			if(sum==k){
				break;
			}
			cnt+=sum;
			sum++;
		}
		cout<<cnt<<"\n";
		
	}
	return 0;
}
