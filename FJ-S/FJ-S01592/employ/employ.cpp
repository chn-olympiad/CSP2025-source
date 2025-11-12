#include <bits/stdc++.h>
using namespace std;
string a;
int n,m,c[505],ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		if(c[i]>0){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
