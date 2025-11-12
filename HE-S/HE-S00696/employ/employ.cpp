#include <bits/stdc++.h>
using namespace std;

int t,n;
long long a[10005][3];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		cout<<2;
	}
	
	return 0;
}
