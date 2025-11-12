#include<bits/stdc++.h>
using namespace std;
int a[500005];
int used[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt=0,ans=0,t=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j;k++){
				cnt^=a[k];
				if(used[k]==1){
					t=1;
				}
			}
			if(cnt==k&&t==0){
				ans++;
				int s=i;
				while(s<=j){
					used[s]=1;
					s++;
				}
			}
			cnt=0;
			t=0;
		}
	}
	cout<<ans;
}
