#include<bits/stdc++.h>
using namespace std;
long long n,m=0;
long long a[5005];
void aaa(){
	int zui=1;
    while(zui<=n){
    	for(int j=1;j<zui-1;j++){
    		for(int t=j+1;t<zui;t++){
    			if(a[j]+a[t]+a[zui]>2*a[zui]){
    				m=m+(zui-t+j);
				}
			}
		}
		zui++;
	}
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(a[j]>a[j+1]&&a[j+1]>=0){
    			swap(a[j],a[j+1]);
			}
		}
	}
	aaa();
	cout<<m;
return 0;
}
