#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
string s;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int f=s.find('1');
	if(f==string::npos){
		cout<<0;
		return 0;
	}
	return 0;
}

