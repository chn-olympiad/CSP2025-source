#include<bits/stdc++.h>
using namespace std;
int a[5020];

int main(){
    int n,j=0,cnt=0,s=0;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdiout);
	scanf("%d",&n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=3;i<=n;i++){
    	while(j<i){
    		for(int k=j;k<j+i;k++)s+=a[k];
            if(a[j+i-1]*2<s){
                cnt++;
        	}s=0;
        	j++;
		}j=0;
	}printf("%d",cnt);
	return 0;
}
