#include<bits/stdc++.h>
using namespace std;
int n,a[5100];
long long s;
int main(){
	freopen("palygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]; 
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++){
				if((a[i]+a[j]+a[k])>max( max(a[i],a[j]) ,a[k] )*2)
					s++;
			}
		}
	}
	cout<<s%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
