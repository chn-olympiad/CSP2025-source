#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long

vector<ll>a,b,c;

void solve(){
	a.clear();
	b.clear();
	c.clear();
	int n;
	cin>>n;
	ll sum=0;
	for(int i=0;i<n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		int ma=max({x,y,z});
		sum+=ma;
		int sma=0;ma=0;
		ma=x;
		if(y>=ma)sma=ma,ma=y;
		else if(y>=sma)sma=y;
		if(z>=ma)sma=ma,ma=z;
		else if(z>=sma)sma=z;
		if(x==ma)a.push_back(ma-sma);
		else if(y==ma)b.push_back(ma-sma);
		else c.push_back(ma-sma);
//		cout<<ma<<" "<<sma<<"\n";
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	for(int i=0;i<max(0,(int)a.size()-n/2);i++)sum-=a[i];
	for(int i=0;i<max(0,(int)b.size()-n/2);i++)sum-=b[i];
	for(int i=0;i<max(0,(int)c.size()-n/2);i++)sum-=c[i];
	cout<<sum<<"\n";
//	cout<<"[ÇëÊäÈëÎÄ±¾] "<<a.size()<<" "<<b.size()<<" "<<c.size()<<"\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
}
