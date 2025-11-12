#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,a[5004],b[5004];
bool cmp(int a,int b){
return a>b;
}
long long cnt;
int main(){
freopen("polygon","r",stdin);
freopen("polygon","w",stdout);
cin>>n;
for(int i=1;i<=n;i++) cin>>a[i],b[i]=b[i-1]+a[i];
sort(a+1,a+n+1,cmp);
for(int i=1;i<=n-2;i++){
    for(int j=i+2;j<=n;j++){
        int lr=b[j]-b[i-1];
        int d=a[i]*2;
        if(lr>=d)cnt++;
    }
}
cout<<cnt;
fclose(stdin);
fclose(stdout);
return 0;
}

