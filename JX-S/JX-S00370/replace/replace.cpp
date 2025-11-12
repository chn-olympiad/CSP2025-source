#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N],a,b;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d %d",&n,&q);
    for (int i=1;i<=n;i++)
        cin>>s1[i]>>s2[i];
    for (int i=1;i<=q;i++){
        cin>>a>>b;
        int l1=a.size();
        int z=0;
        for (int i=1;i<=n;i++){
            int l=a.find(s1[i]);
            if (l>=0 && l<l1){
                int len=s1[i].size();
                string x=a;
                for (int j=l;j<l+len;j++)
                    x[j]=s2[i][j-l];
                if (x==b) z++;
            }
        }
        cout<<z;
    }
    return 0;
}
