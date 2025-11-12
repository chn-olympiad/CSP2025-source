#include<bits/stdc++.h>
using namespace std;
int n,m;
long long sum=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=1;i--) sum*=i;
	cout<<sum;
	return 0;
}
