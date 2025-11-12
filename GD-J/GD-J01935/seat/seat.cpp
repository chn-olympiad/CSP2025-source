#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+5;
int n,m;
int p[maxn][maxn];
vector<pair<int,int>> a;
bool cmp(pair<int,int> x,pair<int,int> y){return x.first>y.first;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int x;
		cin>>x;
		a.push_back(make_pair(x,i));
	}
	sort(a.begin(),a.end(),cmp);
	int x=1,y=1;
	for(int i=0;i<a.size();i++){
//		cout<<x<<' '<<y<<endl;
		p[x][y]=a[i].first;
		if(a[i].second==1){cout<<x<<' '<<y<<endl;return 0;}
		if(y==(x%2?n:1))x++;
		else y+=(x%2?1:-1);
	}
	return 0;
}
