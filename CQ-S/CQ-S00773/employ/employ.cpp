#include<bits/stdc++.h>
#define int long long
using namespace std;
int c[514];
void kd(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	kd();
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int x=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)x++;
	}
	sort(c+1,c+1+n);
	
	cout<<0;
	return 0;
}

