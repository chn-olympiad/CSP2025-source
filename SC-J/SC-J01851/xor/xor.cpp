#include<bits/stdc++.h>
using namespace std;
int n,k,u=1,cnt;
int a[500005];
int b[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			cnt++;
			u=i+1;
		}
		for(int j=u;j<=i;j++){
			b[j]=b[j]^a[i];
			if(b[j]==k){
				cnt++;
				u=i+1;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}