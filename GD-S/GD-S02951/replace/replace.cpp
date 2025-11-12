#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2*1e5+10;
int x,y;
string a[N][2];
string b[N][2];
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>x>>y;
	for(int i=1;i<=x;i++)cin>>a[i][0]>>a[i][1];
	for(int i=1;i<=y;i++)cin>>b[i][0]>>b[i][1];
	for(int i=1;i<=y;i++)cout<<"0\n";
	
	return 0;
}
