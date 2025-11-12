#include<bits/stdc++.h>
using namespace std;
int n,k;
int sum;
int prep[10001],a[10001];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>a[i];
	prep[1]=a[1];
	for(int i=2; i<=n; i++) prep[i]=a[i]^prep[i-1];;
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			int x=prep[i-1],y=prep[j];
			int ans=x^y;
			if(ans==k||i==j&&a[i]==k) {
				sum++;
				i=j+1;
			}
		}
	}
	cout<<sum;
	return 0;
}
