#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=1;
	for(int i=1;i<=n;i++){
		s*=i;
	}
	cout<<s;
	return 0;
}
