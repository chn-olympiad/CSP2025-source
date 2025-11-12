#include<bits/stdc++.h>
using namespace std;
int n,k;
long long cnt;
int a[50005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)
				cnt++;
		}
		cout<<cnt;
		return 0;
	}
	else{
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n-k;i++){
				int ans=0;
				for(int j=i;j<i+k;j++){
					ans+=a[j];
				}
				if(ans==k)
					cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	
	return 0;
}

