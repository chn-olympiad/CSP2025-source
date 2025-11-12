#include<bits/stdc++.h>
using namespace std;
int c[10005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long a=0,b=0;
    cin>>a>>b;
    int o=0,q=0,x=0;
    for(int i=0;i<a;i++){
        cin>>c[i];
    }
    for(int i=0;i<a;i++){
        for(int j=i;j<a;j++){
            o+=c[j];
            if(c[j]!=0){
                q++;
            }

            if(o/q==b){
                x++;
                i=j;
                break;
            }
        }
        o=0;
        q=0;

    }
    cout<<x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
