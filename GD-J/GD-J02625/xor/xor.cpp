#include<bits/stdc++.h>
using namespace std;
int n,k;//序列长度，指定非负整数
int l[50005];//原始数列,异或值数组
int f[50005][50005];
int ans=0; 
int maxi=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	} 
	for(int i=1;i<=n;i++){
		f[i][i]=l[i];
		for(int j=i+1;j<=n;j++){
			f[i][j]=f[i][j-1]^l[j];
		}
	}	
	for(int j=1;j<=n;j++){
		for(int i=maxi+1;i<=j;i++){
			if(f[i][j]==k){
				ans++;
				maxi=i;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
