#include <bits/stdc++.h>
using namespace std;
string r(string a){
    int len=a.size();
    string b;
    for(int i = 0;i<len;i++){
        b+=a[len-i-1];
    }
    return b;
}
string e(int a){
    if(a==0){
        return "0";
    }
    string p;
    while(a!=0){
        p+=char(a%2+'0');
        a/=2;
    }
    return r(p);
}
int z(string a){
    a=r(a);
    int len=a.size(),p=0;
    for(int i = 0;i<len;i++){
        p+=int(a[i]-'0')*pow(2,i);
    }
    return p;
}
int y(int a,int b){
    string as=r(e(a));
    string bs=r(e(b));
    string c;
    int la=as.size(),lb=bs.size();
    while(la>lb){
        bs+="0";
        lb=bs.size();
    }
    while(la<lb){
        as+="0";
        la=as.size();
    }
    for(int i = 0;i<la;i++){
        if(as[i]==bs[i]){
            c+="0";
        }
        else{
            c+="1";
        }
    }
    c=r(c);
    return z(c);
}
int l[50010],f[50010];
bool cheak1(int a,int b){
    for(int i = a;i<=b;i++){
        if(f[i]==1){
            return false;
        }
    }
    return true;
}
bool cheak2(int a,int b,int k){
    int n=l[a];
    for(int i = a+1;i<=b;i++){
        n=y(n,l[i]);
    }
    if(n==k){
        return true;
    }
    return false;
}
void f1(int a,int b){
    for(int i=a;i<=b;i++){
        f[i]=1;
    }
    return;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,sum=0;
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        cin >> l[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            if(cheak1(i,j)&&cheak2(i,j,k)){
                f1(i,j);
                sum++;
                break;
            }
        }
    }
    cout << sum;
    return 0;
}
