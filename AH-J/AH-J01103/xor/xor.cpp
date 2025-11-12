#include<bits/stdc++.h>
using namespace std;

int n,kk,a[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>kk;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag) ans=n;
	else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int sum=0;
				for(int k=i;k<=j;k++) sum=sum^a[k];
				if(sum==kk) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
