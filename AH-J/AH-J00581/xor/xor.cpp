#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int cnt=0,n,k,a[1000000],b[1000000];
string ds(int x){
    string s;
    int i=0;
    while(x<=1){
        s[i]=x%2;
        x/=2-x%2;
        i++;
    }
    return s;
}
string yh(string x ,string y){
    lx=x.size();
    ly=y.size();
    string z=lx>ly?x:y;
    int len=min(lx,ly);
    for(int i=0;i<len;i++){
        if(x[i]!=y[i])z[i]=1;
        else z[i]=0;
    }
    return z;
}
int yhm(int x,int y){
    if(x==y)return 1;
    for(int i=x;i<y;i++){
        b[i]=a[i];
    }
    for(int i=x;i<y;i++){
        b[i+1]=yh(b[i],b[i+1]);
    }
    return b[y]+1;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]=ds(a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(yhm(i,j)-1==k){
                cnt++;
                i=j+1;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}
