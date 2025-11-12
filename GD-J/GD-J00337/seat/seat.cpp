#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,ans=0;
	int a[1005];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=n*m;
	int ma=a[1];
	sort(a+1,a+t);
	for(int i=1;i<=t;i++){
		if(a[i]==ma) {
			k=t-i;
			break;
		}
	}
	for(int i=1;i<=n/2;i++){
		for(int j=1;j<=m;j++){
			ans++;
			if(ans==k){
				printf("%d %d",i,j);
				return 0;
			}
		}
		for(int j=m;j>=1;j--){
			ans++;
			if(ans==k){
				printf("%d %d",i+1,j);
				return 0;
			}
		}
	}
	if(n%2!=0){
		for(int i=1;i<=m;i++){
			ans++;
			if(k==ans) {
				printf("%d %d",n,i);
				return 0;
			}
		}
	}
	return 0;
} 
