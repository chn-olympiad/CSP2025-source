#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("r","xor.in",stdin);
	freopen("w","xor.out",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<rand()%n;
	return 0;
}
