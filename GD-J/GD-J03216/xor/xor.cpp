#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;){
		bool flag=0;
		int j=i;
		while(j<=n){
			int sum=0;
			for(int x=i;x<=j;x++) sum=(sum^a[x]);
			if(sum==k){
				ans++;
				flag=1;
				break;
			}
			j++;
		}
		if(flag) i=j+1;
		else i++;
	}
	cout<<ans;
}
