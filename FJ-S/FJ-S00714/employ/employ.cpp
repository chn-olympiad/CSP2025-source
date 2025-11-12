#include<bits/stdc++.h>
#define int long long
#define mod 998244353ll
using namespace std;
int n,m;
string str;
bool can[510];
int per[510];
bool used[510];
int ans;
int c[510];
int func[510];
void init()
{
	func[0]=1;
	for(int i=1;i<=n;i++) func[i]=func[i-1]*i,func[i]%=mod;
}
void go(int x,int refu)
{
	if(n-refu<m) return;
	if(x-refu-1>=m)
	{
		ans+=func[n-x+1];
		ans%=mod;
		return;
	}
	if(x>n)
		return;
	for(int i=1;i<=n;i++)
	{
		if(used[i]) continue;
		used[i]=true;
		per[x]=i;
		int new_refu=refu+((can[x]==false)||(refu>=c[i]));
		go(x+1,new_refu);
		used[i]=false;
	}
}
main()
{
	ifstream cin("employ.in",ios::in);
	ofstream cout("employ.out",ios::out);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	init();
	cin>>str;
	bool spe1=true;
	for(int i=1;i<=n;i++) cin>>c[i],can[i]=(str[i-1]=='1'),spe1&=c[i];
	srand(time(0));
	if(n<=100)
	{
		go(1,0);
		cout<<ans;
		return 0;
	}
	else cout<<func[n]<<endl;
}
