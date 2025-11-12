#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=1e5+9;
ll cost[N],n,a[N],b[N],c[N],ch[N],book1,book2,book3,sumnow,costout[N],cnt;

inline void solve(){
	cin>>n;
	sumnow=book1=book2=book3=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(a[i]>=b[i] && b[i]>=c[i]) ch[i]=1,cost[i]=a[i]-b[i];
		else if(a[i]>=c[i] && c[i]>=b[i]) ch[i]=1,cost[i]=a[i]-c[i];
		else if(b[i]>=a[i] && a[i]>=c[i]) ch[i]=2,cost[i]=b[i]-a[i];
		else if(b[i]>=c[i] && c[i]>=a[i]) ch[i]=2,cost[i]=b[i]-c[i];
		else if(c[i]>=a[i] && a[i]>=b[i]) ch[i]=3,cost[i]=c[i]-a[i];
		else if(c[i]>=b[i] && b[i]>=a[i]) ch[i]=3,cost[i]=c[i]-b[i];
		sumnow+=max(a[i],max(b[i],c[i]));
	}
	for(int i=1;i<=n;i++){
		if(ch[i]==1) book1++;
		else if(ch[i]==2) book2++;
		else book3++;
	}
	if(book1<=n/2 && book2<=n/2 && book3<=n/2){
		cout<<sumnow<<'\n';
		return void();
	}
	int p=0;
	if(book1>n/2) p=1;
	else if(book2>n/2) p=2;
	else p=3;
	
	cnt=0;
	for(int i=1;i<=n;i++){
		if(ch[i]==p) 
			costout[++cnt]=cost[i];
	}
	sort(costout+1,costout+cnt+1);
	for(int i=1;i<=max(book1,max(book2,book3))-n/2;i++)
		sumnow-=costout[i];
	cout<<sumnow<<'\n';
	return void();
} 

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
