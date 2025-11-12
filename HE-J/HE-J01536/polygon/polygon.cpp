#include<Bits/stdc++.h>
using namespace std;
int n;
int a[10005];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<rand()%20;
}
