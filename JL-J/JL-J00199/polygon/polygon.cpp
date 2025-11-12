#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010]
;int main(){
    freopen("polygon.in","r",stdin);
     freopen("polygon.out","w",stdin);
    int num=0;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    num+=a[i];
    if(n>=3&&num>2*max(num,a[i])){
        cout<<9;
    }
}

fclose(stdin);
fclose(stdout);





return 0;}
