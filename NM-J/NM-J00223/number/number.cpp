#include <bits/stdc++.h>
using namespace std;
string s=" ",a[100005]={""},e=" ",b[100005]={""};
int g=1,cs=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();i++){
            e=s[i];
            if(e>="0"&&e<="9"){
                a[g]=s[i];
                b[g]=a[g];
                g+=1;
            }
    }
    for(int i=1;i<=g-1;i++){
        for(int j=1;j<=g-1;j++){
            if(a[i]<a[i+1]&&cs!=1){
                a[i]=a[i+1];
 //               a[i+1]=b[i];
                cs=0;
            }
        }
    }
    for(int i=0;i<=g;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
