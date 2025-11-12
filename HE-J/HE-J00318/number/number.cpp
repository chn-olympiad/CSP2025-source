#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cout<<n<<" "<<m;
	return 0;
}
