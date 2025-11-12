#include<bits/stdc++.h>
using namespace std;
const int N =5e5+10;
int a[N],n,k;
int ans;
bool vis[N];
int main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=0;j<=n-i;j++){
			if(vis[i+j])	break;
			sum^=a[i+j];
			if(sum==k){
				//cout<<i<<" "<<j<<endl;
				for(int m=i;m<=i+j;m++){
					vis[m]=1;
				}
				ans++;
				break;
			}
		}
	}
	cout<<ans;
}