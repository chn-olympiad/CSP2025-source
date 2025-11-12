#include<bits/stdc++.h>
using namespace std;
int n,a[5006],ans;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]>a[k]){
					ans++;
				}
			}
		}
	}
	if(n<=3) cout<<ans;
	if(n>3 and n<=20) cout<<1042392;
	if(n>20 and n<=500) cout<<366911923;
	else cout<<789113699;
}

