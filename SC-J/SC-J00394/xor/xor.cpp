#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;cin>>n>>k;
    vector<int> a(n+1);
    vector<vector<int> > s(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		cin>>a[i];a[i]^=a[i-1];
	}
	if(k==0){
		cout<<n;return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=n-i;j++){
			s[j][j+i]=a[j+i]^a[j-1];
		}	
	}
	vector<vector<int> > m(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(s[i][j]==k){
				for(int x=i+1;x<=n;x++){
					for(int y=j+1;y<=n;y++)m[x][y]=max(m[x][y],m[i][j]+1);
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)ans=max(ans,m[i][j]);
	}
	cout<<ans;
	return 0;
}