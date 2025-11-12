#include<bits/stdc++.h> 
using namespace std;
int a[500005],n,k,ans=0;
int f[5000][5000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)f[i][i]=a[i];
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			f[i][j]=(f[i][j-1] xor a[j]);
		}
	}
	int r,l;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[i][j]==k && i>r){
				ans++;
				l=i;r=j;
			}
		} 
	}
    cout<<ans;
	return 0;
	
}