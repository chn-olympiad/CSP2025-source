#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long;
const int N=1e5+12;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
using pi=pair<ll,int>;
int n,m;
int T;
int choose[N];
ll a[N],b[N],c[N];
pi cha[N];
ll calc(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(choose[i]==1)ans+=a[i];
		else if(choose[i]==2)ans+=b[i];
		else ans+=c[i];
	}
	return ans;
}
void clear(){
	memset(choose,0,sizeof choose);
	for(int i=1;i<=n;i++)cha[i]={0,0};
}
void solve(){
	cin>>n;
	int tota=0,totb=0,totc=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		int mx=max({a[i],b[i],c[i]});
		if(mx==a[i])tota++,choose[i]=1;
		else if(mx==b[i])totb++,choose[i]=2;
		else totc++,choose[i]=3;
	}
	if(tota<=n/2&&totb<=n/2&&totc<=n/2){
		cout<<calc()<<endl;
	}else if(tota>n/2){
		int mr=tota-n/2;
		int tmp=0;
		for(int i=1;i<=n;i++){
			if(choose[i]==1){
				cha[++tmp]={a[i]-max(b[i],c[i]),i};
			}
		}
		sort(cha+1,cha+tmp+1);
		for(int i=1;i<=mr;i++){
			if(b[cha[i].second]>=c[cha[i].second]){
				choose[cha[i].second]=2;
				totb++;
			}else{
				choose[cha[i].second]=3;
				totc++;
			}
		}
		if(totb<=n/2&&totc<=n/2){
			cout<<calc()<<endl;
		}else if(totb>n/2){
			int mr2=totb-n/2;int tmp2=0;
			for(int i=1;i<=n;i++){
				if(choose[i]==2){
					cha[++tmp2]={b[i]-c[i],i};
				}
			}
			sort(cha+1,cha+tmp2+1);
			for(int i=1;i<=mr2;i++){
				choose[cha[i].second]=3;
			}
			cout<<calc()<<endl;
		}else{
			int mr2=totc-n/2;int tmp2=0;
			for(int i=1;i<=n;i++){
				if(choose[i]==3){
					cha[++tmp2]={c[i]-b[i],i};
				}
			}
			sort(cha+1,cha+tmp2+1);
			for(int i=1;i<=mr2;i++){
				choose[cha[i].second]=2;
			}
			cout<<calc()<<endl;
		}
	}else if(totb>n/2){
		int mr=totb-n/2;
		int tmp=0;
		for(int i=1;i<=n;i++){
			if(choose[i]==2){
				cha[++tmp]={b[i]-max(a[i],c[i]),i};
			}
		}
		sort(cha+1,cha+tmp+1);
		for(int i=1;i<=mr;i++){
			if(a[cha[i].second]>=c[cha[i].second]){
				choose[cha[i].second]=1;
				tota++;
			}else{
				choose[cha[i].second]=3;
				totc++;
			}
		}
		if(tota<=n/2&&totc<=n/2){
			cout<<calc()<<endl;
		}else if(tota>n/2){
			int mr2=tota-n/2;int tmp2=0;
			for(int i=1;i<=n;i++){
				if(choose[i]==1){
					cha[++tmp2]={a[i]-c[i],i};
				}
			}
			sort(cha+1,cha+tmp2+1);
			for(int i=1;i<=mr2;i++){
				choose[cha[i].second]=3;
			}
			cout<<calc()<<endl;
		}else{
			int mr2=totc-n/2;int tmp2=0;
			for(int i=1;i<=n;i++){
				if(choose[i]==3){
					cha[++tmp2]={c[i]-a[i],i};
				}
			}
			sort(cha+1,cha+tmp2+1);
			for(int i=1;i<=mr2;i++){
				choose[cha[i].second]=2;
			}
			cout<<calc()<<endl;
		}
	}else{
		int mr=totc-n/2;
		int tmp=0;
		for(int i=1;i<=n;i++){
			if(choose[i]==3){
				cha[++tmp]={c[i]-max(a[i],b[i]),i};
			}
		}
		sort(cha+1,cha+tmp+1);
		for(int i=1;i<=mr;i++){
			if(a[cha[i].second]>=b[cha[i].second]){
				choose[cha[i].second]=1;
				tota++;
			}else{
				choose[cha[i].second]=2;
				totb++;
			}
		}
		if(tota<=n/2&&totb<=n/2){
			cout<<calc()<<endl;
		}else if(tota>n/2){
			int mr2=tota-n/2;int tmp2=0;
			for(int i=1;i<=n;i++){
				if(choose[i]==1){
					cha[++tmp2]={a[i]-b[i],i};
				}
			}
			sort(cha+1,cha+tmp2+1);
			for(int i=1;i<=mr2;i++){
				choose[cha[i].second]=1;
			}
			cout<<calc()<<endl;
		}else{
			int mr2=totb-n/2;int tmp2=0;
			for(int i=1;i<=n;i++){
				if(choose[i]==2){
					cha[++tmp2]={b[i]-a[i],i};
				}
			}
			sort(cha+1,cha+tmp2+1);
			for(int i=1;i<=mr2;i++){
				choose[cha[i].second]=2;
			}
			cout<<calc()<<endl;
		}
	}
	clear();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(),cout.tie();
	cin>>T;
	while(T--){
		solve();
	}
	
	return 0;
} 
