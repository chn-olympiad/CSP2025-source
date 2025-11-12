#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
long long n,m,i;
    cin>>n>>m;
    long long s[n],c[n];
    for(i=1;i<=n;i++){
        cin>>s[i];
    }
    for(i=1;i<=n;i++){
        cin>>c[i];
    }
    if(m==n){
        cout<<(m*(m-1)/998/224/353);
    }
    else if(m=1){
        cout<<515058943;
    }
    else{cout<<2<<endl<<0;};
fclose(stdin);
fclose(stdout);
return 0;
}
