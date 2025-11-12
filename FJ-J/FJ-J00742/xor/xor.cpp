#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,maxn=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int t=n,p=a[i];
		for(int j=i+1;j<=t;j++){
			p^=a[j];
			if(p==k)maxn++;
			if(j==t){
				t--;
				j=i+1;
				p=a[i];
			}
		}
	}
	cout<<maxn<<endl;
	return 0;
}
