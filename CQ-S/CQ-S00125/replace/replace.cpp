#include<bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
const int N=2e5+5,M=5e6+5;ULL NUM=1e8+7;
int n,m,l[N],r[N],len,ans,st[N];char s1[M],s2[M],t1[M],t2[M];vector<int> def[M];
ULL hs1[M],hs2[M],ht1[M],ht2[M],hs[256],p[N],S1,S2,T1,T2,Ta,Tb;
bool cmp(int a,int b){return r[a]-l[a]>r[b]-l[b];}
int main(){//40pts(?)
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    // double T=time(0);
    scanf("%d%d",&n,&m),srand(time(0)),p[0]=1;
    for(int i=0;i<=200;i++) hs[i]=rand();
    for(int i=1;i<=n;i++){
        l[i]=r[i-1]+1,scanf(" %s %s",s1+l[i],s2+l[i]),r[i]=strlen(s1+1),
        p[i]=p[i-1]*NUM,hs1[l[i]]=hs[s1[l[i]]],hs2[l[i]]=hs[s2[l[i]]];
        for(int j=l[i]+1;j<=r[i];j++) hs1[j]=hs1[j-1]*NUM+hs[s1[j]],hs2[j]=hs2[j-1]*NUM+hs[s2[j]];
        st[i]=l[i-1];
        for(int j=l[i];j<=r[i];j++) if(s1[j]!=s2[j]){st[i]=j;break;}
        def[st[i]-l[i]+1].push_back(i);
    }
    for(int i=0;i<=r[n];i++) sort(def[i].begin(),def[i].end(),cmp);
    for(int i=1,st=0;i<=m;i++){
        scanf(" %s %s",t1+1,t2+1),len=strlen(t1+1),ans=st=0;
        if(strlen(t1+1)!=strlen(t2+1)) {printf("0\n");continue;}
        for(int i=1;i<=len;i++) st==0&&t1[i]!=t2[i]?st=i:0,ht1[i]=ht1[i-1]*NUM+hs[t1[i]],ht2[i]=ht2[i-1]*NUM+hs[t2[i]];
        for(int i=1;i<=len;i++){
            int tmp=(st==0?0:st-i+1),L=i,R;
            for(int j:def[tmp]){
                // cout<<"* "<<i<<' '<<j<<' '<<st-i+1<<' '<<::st[j]-l[j]+1<<'\n';
                if((R=i+r[j]-l[j])>len||::st[j]-l[j]+1!=st-i+1&&!(st==0&&::st[j]==0)) continue;
                S1=hs1[r[j]],S2=hs2[r[j]],T1=ht1[R]-ht1[L-1]*p[R-L+1],T2=ht2[R]-ht2[L-1]*p[R-L+1],Ta=ht1[len]-ht1[R]*p[len-R],Tb=ht2[len]-ht2[R]*p[len-R];
                if(S1==T1&&S2==T2&&Ta==Tb) ans++;
                if(Ta!=Tb) break;
            }
            if(t1[i]!=t2[i]) break;
        }
        printf("%d\n",ans);
    }
    // printf("\n%.5lf",time(0)-T);
    return 0;
}