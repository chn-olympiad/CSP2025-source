#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[10100];

bool yun(int x,int y,int ans){
	int yi[10100];
	//int he[10100];
	int hu[10100];
	yi[1] = a[x];
	hu[1] = a[x];
	//he[1] = a[x];
	int k = 2;
	for(int i  = x;i<=y;i++){
		yi[k] = yi[k-1] ^ a[i];
		//he[k] = he[k-1] & a[i];
		hu[k] = hu[k-1] | a[i];
		k++;
	}
	
	if(yi[k] == ans && hu[k] == ans){
		return 1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>ans;
	
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int ma  = 0;
	for(int i  = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			if(yun(i,j,ans) == 1 && j-i>=ma){
				ma  = j-i;
			}
			
		}
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 