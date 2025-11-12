#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[90000];
string jz(int a){
    int q[9999999];
    string w;
int i=1;
while(a>0){
q[i]=a%2;
a=a/2;
i++;
}
for(int j=i-1;j>=1;j--){
    w[j]=char(q[j]+48);
}
return w;
}
string yh(string a,string b){
    string c;
    for(int i=1;i<=max(a.size(),a.size());i++){
        if(a[i]==b[i]){
            c[i]=0;
        }else{
        c[i]=1;
        }
    }
    return c;
}
bool ch(int x,int y){
    string ans;
    for(int i=x;i<=y;i++){
       if(i==x){
        ans=jz(a[i]);
       }else{
       ans=yh(jz(a[i]),ans);
       }
    }
    if(ans==jz(k)){
        return true;
    }
    return false;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen(".out","w",stdout);
int mx=0;
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
        if(ch(i,j)){
            if(j-i+1>mx){
                mx=j-i+1;
            }
        }
    }
}
cout<<mx;
return 0;
}
