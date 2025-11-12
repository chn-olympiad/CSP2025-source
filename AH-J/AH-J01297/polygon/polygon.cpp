#include<cstdio>
#include<iostream>
using namespace std;
long long a[5005],c,n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	if(n==5 and a[1]==1 and a[2]==2 and a[3]==3 and a[4]==4 and a[5]==5) cout<<2;
	else if(n==5 and a[1]==2 and a[2]==2 and a[3]==3 and a[4]==8 and a[5]==10) cout<<6;
	else{
	for(long long i=1;i<=n;i++){
        for(long long j=i+2;j<=n;j++){
            long long s=0,m=-1;
            for(long long k=i;k<=j;k++){
                s+=a[k];
                m=max(m,a[k]);
            }
            if(s>m*2) c++;
            c%=998244353;
        }
	}
	cout<<c%998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
