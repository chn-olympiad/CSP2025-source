#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,c=0;
    scanf("%d%d",&n,&q);
    string s1,s2;
    cin>>s1>>s2;
    char a[1000005];
    for(int i=1;i<=n;i++){
            if(s1==s2){
                    c++;
            }
    }
    for(int i=1;i<=q;i++){
        cin>>a[i];
        if(a[i]==a[i+1]){
            c++;
        }
    }
    for(int i=1;i<=q;i++){
        printf("%d\n",c);
    }
    return 0;
}
