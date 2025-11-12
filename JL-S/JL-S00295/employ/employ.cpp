#include<bits/stdc++.h>
using namespace std;
int f(int a){
    int b,c=1;
    for(b=1;b<=a;b++){
        c*=b;
    }
    return c;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int a,b;
    cin>>a>>b;
    string c;
    cin>>c;
    int d[a],e;
    for(e=0;e<a;e++){
        cin>>d[e];
    }
    if(b==a){
        sort(d,d+a);
        for(e=0;e<a;e++){
            if(c[e]=='0' or d[e]==0){
                cout<<0;
                return 0;
            }
        }
        long long f=a,g=1;
        while(f--){
            g*=f+1;
            g%=998244353;
        }
        cout<<g;
        return 0;
    }
    if(a>25){
        cout<<0;
        return 0;
    }
    sort(d,d+a);
    long long h=0;
    for(e=0;e<f(a);e++){
        int f,g=0,i=0;
        for(f=0;f<a;f++){
            if(c[f]=='0' or d[f]<=g){
                g++;
            }
            else{
                i++;
            }
            if(i>=b){
                h++;
                break;
            }
        }
        next_permutation(d,d+a);
    }
    cout<<h%998244353;
    return 0;
}
