#include<bits/stdc++.h>
using namespace std;
char s1[105][2005],s2[105][2005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%s%s",s1[i]+1,s2[i]+1);
    for(int i=1;i<=q;i++){
        long long ans=0;
        string t1="",t2="";
        cin >> t1 >> t2;
        int l1=t1.length(),l2=t2.length();
        for(int j=1;j<=n;j++){
            int fl=0;
            for(int k=0;k<l1;k++){
                int t=0;
                if(t1[k]==t2[k])continue;
                if(fl){
                    fl++;break;
                }
                while(s1[t+1]==s1[k]&&t<=l2)k++,t++;
                fl=1;
            }
            if(fl!=2)ans++;
        }
        printf("0\n");
    }
}