#include<bits/stdc++.h>
using namespace std;
int a[100001];
int s[100001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int c,r,sum;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	for(int i=1;i<=n*m;i++){
		if(a[i]<a[i+1]) sum=a[i+1];
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
