#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long l,n=0,c=0,z;
    string s;
    cin>>s;
    l=s.size();
    for(long long i=0;i<=l-1;i++) if(s[i]>='0'&&s[i]<='9') n++;
    long long a[n];
    long long d[n];
    for(long long i=0;i<=l-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[c]=s[i]-'0';
            c++;
        }
    }
    for(long long i=0;i<=n-1;i++){
            d[i]=0;
    for(long long j=0;j<=n-1;j++){
        if(a[j]>d[i]){
            d[i]=a[j];
            z=j;
        }
    }
    for(long long k=0;k<=n-1;k++) if(k==z) a[k]=0;
    }
    for(long long i=0;i<=n-1;i++) cout<<d[i];
    return 0;
}
