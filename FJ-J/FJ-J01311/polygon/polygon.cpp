#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[5010]; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	srand(time(0));
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int s=rand()%n+1;
	cout<<a[s]+n;
	return 0;
}

