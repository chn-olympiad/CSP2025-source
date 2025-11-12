#include <bits/stdc++.h>
using namespace std;
int oy=0;
int a[100010];
int n,k;
int ans=0;
bool check(int x,int y){
	int sumn=a[x];
	for(int i=x+1;i<=y;i++){
		sumn^=a[i];
	}
	if(sumn==k){
		oy=y;
		return true;
	}
	return false;
}
signed main(){
	freopen("xor.in","r",sidin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i<=oy){
				break;
			}
			else if(i==j&&i==k){
				oy=i;
				ans++;
			}
			else{
				if(check(i,j)){
					ans++;
				}	
			}	
		}
	}
	cout<<ans;
	return 0;
}

