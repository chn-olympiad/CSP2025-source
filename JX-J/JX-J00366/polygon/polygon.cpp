#include<bits/stdc++.h>
using namespace std;
long long n,m,k=0,x,y,q,a[5050],b[5050];
int main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout); 
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    a[0]=b[0]=0;
    for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
    for(int i=3;i<=n;i++)
        if(b[i-1]>a[i])
            for(int j=2;j<i;j++)
                for(int p=1;p<j;p++)
                    if(b[j]-b[p-1]>a[i]) k++;
    cout<<k%998244353;
	return 0;
}