#include<bits/stdc++.h>
using namespace std;
int s[500005],a[500005];
int f(int x,int y){
	return x^y;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	 for(int j=i;j<=n;j++){
		 if(f(s[j],s[i-1])==k){
			 cnt++;
			 i=j;
			 j=n;
		 }
	 }
	cout<<cnt;
	return 0;
}
