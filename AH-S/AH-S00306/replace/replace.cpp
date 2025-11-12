#include<bits/stdc++.h>
using namespace std;
int n,q,maxchar;
long long ans;
string flag1,flag2,flag3;
struct node{
    int nxtchar[30],depth;
    vector<string> change;
}a[5000010];
int nwfrm,temp,j,k,h;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%s %s",flag1,flag2);
        nwfrm=0;
        for(int i=0;flag1[i]!='\0';i++){
            temp=flag1[i]-'a'+1;
            if(a[nwfrm].nxtchar[temp]!=0)
                nwfrm=a[nwfrm].nxtchar[temp];
            else{
                maxchar++;
                a[nwfrm].nxtchar[temp]=maxchar;
                a[maxchar].depth=a[nwfrm].depth+1;
                nwfrm=maxchar;
            }
        }
        a[nwfrm].change.push_back(flag2);
    }
    int p,u,g,c,tt;
    bool flagg;
    for(int i=1;i<=n;i++){
        ans=0;
        scanf("%s %s",flag1,flag2);
        for(j=0;flag1[j]==flag2[j];j++);
        for(h=j+1;flag1[h]!='\0';h++){
            if(flag1[h]!=flag2[h])
                k=h;
        }
        flag1[h]='z'+1;
        for(g=0;g<=j;g++){
            for(p=0,u=g;u<h && a[p].nxtchar[flag1[u]-'a'+1]!=0;p=a[p].nxtchar[flag1[u]-'a'+1],g++);
            if(u<k || u==h && a[p].nxtchar[flag1[u]-'a'+1]!=0)
                continue;
            flagg=1;
            for(int z=0;z<h;z++)
                if((z<=u-a[p].depth || z>=g) && flag1[z]!=flag2[z]){
                    flagg=0;
                    break;
                }
            if(flagg==0)
                break;
            for(c=0;c<a[p].change.size();c++){
                flagg=1;
                for(tt=0;a[p].change[c][tt]!='\0';tt++)
                    if(a[p].change[c][tt]!=flag2[u-a[p].depth+tt+1]){
                        flagg=0;
                        break;
                }
            }
            if(flagg)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
