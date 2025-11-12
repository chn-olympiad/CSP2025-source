#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("ploygon.in","r",stdin);
    freopen("ploygon.out","w",stdout);
    long long n,s[10010],g;
    long long ans=0,max1=0,sum=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
		cin>>s[i];
	}
	for(long long i=1;i<=n;i++){
		if(s[i]>max1)max1=s[i];
	}g=max1*2;
	for(long long i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		    sum+=s[i];
		}
	    if(sum>g){
		    ans++;
		    sum=0;
	    }else sum=0;
    }
	cout<<ans%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;

}
