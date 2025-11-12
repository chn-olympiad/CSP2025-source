#include<bits/stdc++.h>
using namespace std;
struct ax{
    string a,b;
};
int n,m,k,q,ans[10005];
long long lk=18446744073709551615;
ax na[100005],ka[100005];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>na[i].a>>na[i].b;
    }
    for(int i=1;i<=k;i++){
        cin>>ka[i].a>>ka[i].b;
        for(int j=1;j<=n;j++){
            string s=na[j].a;
            int g=s.size();
            if(ka[i].a.find(na[j].a)!=lk){
                for(int k=0;k+g<ka[i].a.size();k++){
                    if(ka[i].a.substr(k,k+g-1)==s){
                        ans[i]++;
                    }
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
