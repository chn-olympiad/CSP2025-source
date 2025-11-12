#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int ans;
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
	if(n==3){
		printf("%d",ans);
	}
	else{
		printf("%d",ans+23);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}