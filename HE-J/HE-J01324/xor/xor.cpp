#include<bits/stdc++.h>
using namespace std;
int a[100001];
int s[100001];
int m[100001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum;
	cin>>n>>k;
	for(int i=0;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++) m[i]=s[i]^k; sum++;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
