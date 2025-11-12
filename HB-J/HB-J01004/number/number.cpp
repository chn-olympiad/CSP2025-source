#include<bits/stdc++.h>
using namespace std;
long long a,s,d[100]={0};
int main(){
    string f;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>f;
    for(a=0;a<f.size();a++){
        if(f[a]<='9'&&f[a]>='0'){
            d[f[a]-'0']++;
        }
    }
    for(a=9;a>=0;a--){
        if(d[a]>0){
            for(s=0;s<d[a];s++){
                printf("%lld",a);
            }
        }
    }
    return 0;
}
