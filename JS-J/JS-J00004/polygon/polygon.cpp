#include <bits/stdc++.h>
using namespace std;
int a[5000],d[25000100],n,s,cunt,b=1,minn;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
	    scanf("%d",&a[i]);
	    if(a[i]>1){
		    b=0;
		}
	}
	if(b==1){
		s=1;
		for(int i=0;i<n;i++){
		    s=s<<1;
		    s%=998244353;
		}
		printf("%d",(s+998244352-n*(n+1)/2)%998244353);
    }
	else{
	    sort(a,a+n);
        d[0]=1;
        d[a[0]]=1;
		s=a[0];
		for(int i=1;i<n;i++){
			for(int j=s;j>=0;j--){
				d[j+a[i]]=(d[j+a[i]]+d[j])%998244353;
				if(j>a[i]){
				    cunt=(cunt+d[j])%998244353;
				}
			}
			s+=a[i];
		}
		printf("%d",cunt);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
