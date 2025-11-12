#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,maxid=-1,ans=0,c1=0,c2=0;
	cin>>n>>k;
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)c1++;
		if(a[i]==1)c2++;
	}
	if(k==0){
		cout<<c1+c2/2;
		return 0;
	}
	if(k==1){
		cout<<c2;
		return 0;
	}
	vector<vector<int>>b(n+1,vector<int>(n+1,0));
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j<=maxid)break;
			b[i][j]=b[i][j-1]^a[j];
			if(b[i][j]==k){
				maxid=max(maxid,j);
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
