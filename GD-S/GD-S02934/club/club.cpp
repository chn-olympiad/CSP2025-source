#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
inline void mret(int e) {
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	system("pause");
	exit(e);
}
class mydp{
public:
	int ca=0,cb=0,cc=0;
	ll ans=0;
	mydp(int h1=0,int h2=0,int h3=0,ll h4=0){
		ca=h1,cb=h2,cc=h3,ans=h4;
	}
	bool operator<(const mydp dp2)const{
		return ans<dp2.ans;
	}
};
class stt{
public:
	int a=0,b=0,c=0;
	stt(int c2=0,int d=0,int e=0){
		a=c2,b=d,c=e;
	}
};
bool cmp(stt a,stt b){
	int ka=max(max(a.a,a.b),a.c),kb=max(max(b.a,b.b),b.c);
	return ka>kb;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<mydp>>dp(n+1,vector<mydp>(4));
		vector<stt>f(n+1,stt(0,0,0));
		vector<int>a(n+1,0),b=a,c=a;
		for(int i=1;i<=n;i++){
			cin>>f[i].a>>f[i].b>>f[i].c;
		}
		stable_sort(f.begin()+1,f.end(),cmp);
		for(int i=1;i<=n;i++){
			a[i]=f[i].a,b[i]=f[i].b,c[i]=f[i].c;
			//cout<<a[i]<<' '<<b[i]<<' '<<c[i]<<endl;
		}
		dp[1][1]=mydp(1,0,0,a[1]),dp[1][2]=mydp(0,1,0,b[1]),dp[1][3]=mydp(0,0,1,c[1]);
		for(ll i=2;i<=n;i++){
			for(ll j=1;j<=3;j++){
				auto k=dp[i-1][j];
				if(k.ca+1 <= n/2 && k.ans + a[i] > dp[i][1].ans)
					dp[i][1] = mydp(k.ca + 1, k.cb, k.cc, k.ans + a[i]);
			}
			for(ll j=1;j<=3;j++){
				auto k=dp[i-1][j];
				if(k.cb+1 <= n/2 && k.ans + b[i] > dp[i][2].ans)
					dp[i][2] = mydp(k.ca, k.cb + 1, k.cc, k.ans + b[i]);
			}
			for(ll j=1;j<=3;j++){
				auto k=dp[i-1][j];
				if(k.cc+1 <= n/2 && k.ans + c[i] > dp[i][3].ans)
					dp[i][3] = mydp(k.ca, k.cb, k.cc + 1, k.ans + c[i]);
			}
		}
		/*for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				cout<<'('<<dp[i][j].ca<<','<<dp[i][j].cb<<','<<dp[i][j].cc<<')'<<dp[i][j].ans<<' ';
			}
			cout<<endl;
		}*/
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				ans=max(ans,dp[i][j].ans);
			}
		}
		cout<<ans<<endl;
	}
	mret(0);
}
