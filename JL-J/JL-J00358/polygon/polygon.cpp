#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	long long a;
	cin>>a;
	long long b[a],c,d=0;
	for(c=0;c<a;c++){
        cin>>b[c];
        if(b[c]!=1){
            d=1;
        }
	}
	if(d==0){
        long long e=1,f=a;
        while(f--){
            e*=2;
            e%=998244353;
        }
        e-=(a*(a+1))/2+1;
        cout<<(e%998244353+998244353)%998244353;
        return 0;
	}
	long long e[a],f,k=0;
	memset(e,0,sizeof(e));
	for(f=0;f<pow(2,a);f++){
        long long g=0,h=0,i,j=0;
        for(i=0;i<a;i++){
            if(e[i]==1){
                j++;
                g+=b[i];
                h=max(h,b[i]);
            }
        }
        if(j>=3 and g>2*h){
            k++;
        }
        e[0]++;
        for(i=0;i<a-1;i++){
            e[i+1]+=e[i]/2;
            e[i]%=2;
        }
	}
	cout<<k%998244353;
	return 0;
}
