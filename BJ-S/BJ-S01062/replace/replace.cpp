#include<bits/stdc++.h>
using namespace std;
long long n,q,lg[200005];
string s1[200005],s2[200005],q1,q2;
unsigned long long ha[5000006],bs[5000006],hi[200005],has[5000006];
inline unsigned long long zd(long long l,long long r){
    return ha[r]-ha[l-1]*bs[r-l+1];
}
inline unsigned long long zd2(long long l,long long r){
    return has[r]-has[l-1]*bs[r-l+1];
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    bs[0]=1;
    for(int i=1;i<=5000000;i++)bs[i]=bs[i-1]*131;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        lg[i]=s1[i].length();
        s1[i]=" "+s1[i],s2[i]=" "+s2[i];
        for(int j=1;j<=lg[i];j++){
            hi[i]=hi[i]*131+s1[i][j];
        }
    }
    while(q--){
        cin>>q1>>q2;
        if(q1.length()!=q2.length()){
            printf("0\n");
            continue;
        }
        long long l=q1.length();
        q1=" "+q1;
        q2=" "+q2;
        long long st,ed;
        for(int i=1;i<=l;i++){
            if(q1[i]!=q2[i]){
                st=i;
                break;
            }
        }
        for(int i=1;i<=l;i++){
            has[i]=has[i-1]*131+q1[i];
        }
        for(int i=l;i>=1;i--){
            if(q1[i]!=q2[i]){
                ed=i;
                break;
            }
        }
        unsigned long long ji=0;
        for(int i=st;i<=ed;i++){
            ji=ji*131+q2[i];
        }
       // printf("%lld %lld\n",st,ed);
        ha[0]=0;
        long long ans=0;
        ha[0]=0;
        for(int i=1;i<=l;i++){
            if(lg[i]>l || lg[i]<ed-st+1)continue;
            ha[0]=0;
            for(int j=1;j<=lg[i];j++){
                ha[j]=(unsigned long long)ha[j-1]*131+s2[i][j];
                //printf("%lld ",(long long)ha[j]);
            }
            for(int j=1;j<=lg[i];j++){
                //if(j==4)printf("%lld",has[5]);
                if(j>=ed-st+1 && zd(j-(ed-st),j)==ji && hi[i]==zd2(st-(j-(ed-st))+1,ed+lg[i]-j)){
                   // printf("123");
                    ans++;
                }
            }
        }
        printf("%lld\n",ans);
    }
}