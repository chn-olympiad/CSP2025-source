#include<bits/stdc++.h>
using namespace std;
int n,k,a[500000+10][2],ans,l;//0为数，1为前缀和

int main(){
	l= 0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		a[i][1]=a[i][0]^a[i-1][1];
		
	}
	for(int i = 1;i<=n;i++){
		for(int j=i;j>l;j--){
			if((a[j-1][1]^a[i][1])==k){
				ans++;
				l=i;
				break;
			}
		}
	}
	cout<<ans;
}
		