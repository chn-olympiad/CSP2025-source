#include <bits/stdc++.h>;
using namespace std;
const int N=25;
int l[N];
int t=0;
string zhuan(int a){
    string m;
    while(a>0){
        if(a%2==0){
            m+='2';
        }
        else{
            m+='1';
        }
        a/=2;
    }
    return m;
}

int main (){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    for(int i=0;i<pow(2,n);i++){
        int sum=0,maxn=0;
        string s=zhuan(i);
        for(int j=0;j<s.size();j++){
            if(s[j]=='1'){
                sum+=l[j];
                maxn=max(maxn,l[j]);
            }
        }
        if(maxn*2<sum){
            t++;
        }

    }
    cout<<t%998244353;
    return 0;
}
