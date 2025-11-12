#include<bits/stdc++.h>
using namespace std;
int a[114514];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ss=0;
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];if(a[i]==1)ss++;}
	if(ss==n)cout<<n-2;
	return 0;
}
