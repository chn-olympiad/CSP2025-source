//多测不清空，保龄两行泪
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+100;
int a1[N],a2[N],a3[N];
int a1n[N],a2n[N],a3n[N];
int cnt[4];
int t,sum,n;
int read(){
    int x=0,w=1;
    char ch=getchar();
    for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')w=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
    return x*w;
}
bool cmp(int x,int y){
    return max(a1[x],max(a2[x],a3[x]))*2-(a1[x]+a2[x]+a3[x])+min(a1[x],min(a2[x],a3[x]))<max(a1[y],max(a2[y],a3[y]))*2-(a1[y]+a2[y]+a3[y])+min(a1[y],min(a2[y],a3[y]));
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--){
        n=read();
        for(int i=1;i<=n;i++)a1[i]=read(),a2[i]=read(),a3[i]=read();
        for(int i=1;i<=n;i++){
            if(a1[i]>=a2[i]&&a1[i]>=a3[i]){a1n[++a1n[0]]=i;cnt[1]++;sum+=a1[i];}
            else if(a2[i]>=a1[i]&&a2[i]>=a3[i]){a2n[++a2n[0]]=i;cnt[2]++;sum+=a2[i];}
            else{a3n[++a3n[0]]=i;cnt[3]++;sum+=a3[i];}
        }
        if(cnt[1]>n/2){
            sort(a1n+1,a1n+a1n[0]+1,cmp);
            for(int i=1;i<=cnt[1]-n/2;i++)sum=sum-a1[a1n[i]]+max(a2[a1n[i]],a3[a1n[i]]);
        }
        else if(cnt[2]>n/2){
            sort(a2n+1,a2n+a2n[0]+1,cmp);
            //cout<<cnt[2]<<' '<<cnt[2]-n/2<<endl;
            for(int i=1;i<=cnt[2]-n/2;i++)sum=sum-a2[a2n[i]]+max(a1[a2n[i]],a3[a2n[i]]);
        }
        else if(cnt[3]>n/2){
            sort(a3n+1,a3n+a3n[0]+1,cmp);
            for(int i=1;i<=cnt[3]-n/2;i++)sum=sum-a3[a3n[i]]+max(a2[a3n[i]],a1[a3n[i]]);
        }
        //for(int i=1;i<=a2n[0];i++)cout<<a2n[i]<<' ';
        //out<<endl<<endl;
        cout<<sum<<endl;
        sum=0;
        a1n[0]=0,a2n[0]=0,a3n[0]=0;
        cnt[1]=0,cnt[2]=0,cnt[3]=0;
    }

    return 0;
}
