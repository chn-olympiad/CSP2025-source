#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010],k=1,d=2,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int z=i+2;z<=n;z++){
				if(a[i]+a[i+k]>a[i+k+d]&&a[i+k]-a[i]<a[i+k+d]){
					sum++;
					}
				d++;
				}
			k++;
			}
		}
	cout<<sum;
	
	
	fclose(stdin);
	fclose(stdout);
}
