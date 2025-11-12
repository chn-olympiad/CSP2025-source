#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n,q,xz2=1;
    scanf("%d %d",&n,&q);
    long long ans[q]={};
    string s1[n]={},s2[n]={},t1[q]={},t2[q]={};
    int s1l[n],s2l[n],t1l[q],t2l[q];
    int sc[n],tc[q];
    int s1b[n],s2b[n],t1b[q],t2b[q];
    int sbc[n],tbc[q];
    for(int i=0;i<n;i++){
        cin>>s1[i]>>s2[i];
        if(xz2){
            for(int j=0;j<s1[i].length();j++){
                if(s1[i][j]!='a'&&s1[i][j]!='b') xz2=0;
                if(s1[i][j]=='b') s1b[i]=j;
            }
            for(int j=0;j<s2[i].length();j++){
                if(s2[i][j]!='a'&&s2[i][j]!='b') xz2=0;
                if(s2[i][j]=='b') s2b[i]=j;
            }
        }
    }
    for(int i=0;i<q;i++){
        cin>>t1[i]>>t2[i];
        if(xz2){
            for(int j=0;j<t1[i].length();j++){
                if(t1[i][j]!='a'&&t1[i][j]!='b') xz2=0;
                if(t1[i][j]=='b') t1b[i]=j;
            }
            for(int j=0;j<t2[i].length();j++){
                if(t2[i][j]!='a'&&t2[i][j]!='b') xz2=0;
                if(t2[i][j]=='b') t2b[i]=j;
            }
        }
    }
    //if(xz2){
        for(int i=0;i<n;i++){
            s1l[i]=s1[i].length(),s2l[i]=s2[i].length();
            sc[i]=s2l[i]-s1l[i];
            sbc[i]=s2b[i]-s1b[i];
        }
        for(int i=0;i<q;i++){
            t1l[i]=t1[i].length(),t2l[i]=t2[i].length();
            tc[i]=t2l[i]-t1l[i];
            tbc[i]=t2b[i]-t1b[i];
        }
        for(int i=0;i<q;i++){
            for(int j=0;j<n;j++){
                if(tc[i]!=sc[j]) continue;
                if(tbc[i]!=sbc[j]) continue;
                if(t1l[i]<s1l[i]||t2l[i]<s2l[i]) continue;
    //            if(t1b[i]<s1b[j]||t1l[i]-t1b[i]<s1l[i]-s1b[i]) continue;
    //            if(t2b[i]<s2b[j]||t2l[i]-t2b[i]<s2l[i]-s2b[i]) continue;
                ans[i]++;
            }
            printf("%lld\n",ans[i]);
        }
     //   return 0;
    //}


    fclose(stdin);
    fclose(stdout);
    return 0;
}
