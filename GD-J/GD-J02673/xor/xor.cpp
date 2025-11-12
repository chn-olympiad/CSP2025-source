#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long vis[5005][5005],a[5005];
	int n;
	long long k,num=0;
	cin>>n>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j+=2){
				num++; 
			}
		}
		cout<<num<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			num++; 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;i<=n;j++){
			vis[i][j]=vis[i][j-1]^a[j];
			if(vis[i][j]==k){
				num++;
			}
		}
	}
	cout<<num<<endl;
	return 0;
}
