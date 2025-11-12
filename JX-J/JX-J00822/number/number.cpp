#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,z;
    int a[]{0};
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(!islower(s[i])){
            z+=s[i];
        }
    }
    for(int i=0;i<z.size();i++){
        a[i]=z[i]-'0';
        a[i+1]=-1;
    }
    int n=0;
    while(true){
        int maxn=0;
        for(int i=0;a[i]!=-1;i++){
            maxn=max(a[i],maxn);
        }
        if(maxn<0){
            break;
        }
        for(int i=0;a[i]!=-1;i++){
            if(maxn==a[i]){
                a[i]=-2;
                break;
            }
        }
        n*=10;
        n+=maxn;
    }
    cout<<n;



    return 0;
}
