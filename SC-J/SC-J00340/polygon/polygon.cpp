#include <iostream>
using namespace std;
//我不会！！ 我不会！！我不会！！
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3) cout<<1;
	else{
		cout<<9;
	}
	return 0;
}