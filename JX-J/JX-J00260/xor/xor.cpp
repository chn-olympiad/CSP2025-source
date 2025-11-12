#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,m;
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int s=0;
			for(int k=i;k<=j;k++){
				s=s^a[k];
			}
			int cnt=j-i;
			if(s==m&&cnt>ans) ans=cnt;
		}
	}	
	cout<<ans<<endl;
	return 0;
}
