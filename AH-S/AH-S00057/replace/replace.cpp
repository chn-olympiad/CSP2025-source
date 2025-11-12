#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005],t1,t2;
int n,q,a[200005],b[200005],c,d;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        a[i]=s1[i].find('b');b[i]=s2[i].find('b');
    }
    while(q--){
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            printf("0");continue;
        }c=t1.find('b');d=t2.find('b');
        int ans=0;
        for(int i=1;i<=n;i++){
            if(c>=a[i]&&t1.size()-d>=s1[i].size()-b[i]&&d-c==b[i]-a[i])ans++;
        }printf("%d\n",ans);
    }
    return 0;
}
