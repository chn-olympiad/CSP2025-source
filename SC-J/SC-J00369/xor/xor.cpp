#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,x;
bool a[500002][22]=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		int j=1;
		while(x){
			a[i][j]=x%2;
			x/=2;j++
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=20;j++){
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}