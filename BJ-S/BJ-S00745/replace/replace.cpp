#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005],b[200005],c[200005];
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        int l=a[i].size();
        for(int j=0;j<l;j++){
            if(a[i][j]=='b'){
                c[i]=j;
                break;
            }
        }
    }

    for(int i=1;i<=q;i++){
        string t1,t2;
        cin>t1>>t2;
        int cc=0;
        int l1=t1.size();
        for(int j=0;j<l1;j++){
            if(a[j]=='b'){
                cc=j;
                break;
            }
        }
        for(int j=1;j<=n;j++){
            int l=a[j].size();
            if(cc>=c[j]){
                string s=t1;
                for(int t=cc-c[j];t<=cc-c[j]+l-1;t++)
                    s[t]=b[t-(cc-c[j])];
                if(s==t2)
                    s1++;
            }
        }
        printf("%d\n",s1);
    }
    return 0;
}
