#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct stu{
    int order;
    int value;
}tmp;
vector<stu>lis[1000005];
int a[10005],b[10005],c[15],d[15][10005];
int aa[15],bb[15],dd[15],coulai[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        tmp.order=v;
        tmp.value=w;
        lis[u].push_back(tmp);
        tmp.order=u;
        lis[v].push_back(tmp);
    }
    if(k==0){
        long long s1=0;
        int bs=0,x;
        b[1]=1;
        for(;;){
            int flag=1;
            for(int i=1;i<=n;i++){
                if(b[i]==1){
                    if(flag){
                        x=i;
                        flag=0;
                    }
                    else{
                        if(a[i]<a[x])
                            x=i;
                    }
                }
            }
            b[x]=2;
            s1+=a[x];
            bs++;
            if(bs>=n) break;
            int l=lis[x].size();
            for(int i=0;i<l;i++){
                int no=lis[x][i].order,va=lis[x][i].value;
                if(b[no]==0){
                    a[no]=va;
                    b[no]=1;
                }
                if(b[no]==1)
                    a[no]=min(va,a[no]);
            }
        }
        printf("%lld",s1);
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)
            scanf("%d",&d[i][j]);
    }
    long long s1=0,tmpp;
    int bs=0,x;
    b[1]=1;
    for(;;){
        //cout<<"s1="<<s1<<endl;
        int flag=1;
        for(int i=1;i<=n;i++){
            if(b[i]==1){
                if(flag){
                    x=i;
                    flag=0;
                }
                else{
                    if(a[i]<a[x])
                        x=i;
                }
            }
        }
        int xd=a[x],flag2=0;
        for(int i=1;i<=k;i++){
            if(bb[i]==1){
                if(aa[i]<xd){
                    x=i;
                    xd=aa[i];
                    flag2=1;
                }
            }
        }
        //if(flag2)
        //    cout<<"co="<<x<<endl;
        //else
        //    cout<<"ci="<<x<<endl;
        if(flag2){
            bb[x]=2;
            tmpp=aa[x];
            s1+=tmpp;
            dd[x]++;
            for(int i=1;i<=n;i++){
                int va=d[x][i];
                if(b[i]==0){
                    a[i]=va;
                    b[i]=1;
                    coulai[i]=x;
                }
                if(b[i]==1){
                    if(va<a[i]){
                        a[i]=va;
                        coulai[i]=x;
                    }
                }
            }
            continue;
        }
        if(coulai[x]>0){
            dd[coulai[x]]++;
        }
        b[x]=2;
        tmpp=a[x];
        s1+=tmpp;
        bs++;
        if(bs>=n) break;
        int l=lis[x].size();
        for(int i=0;i<l;i++){
            int no=lis[x][i].order,va=lis[x][i].value;
            if(b[no]==0){
                a[no]=va;
                b[no]=1;
                coulai[no]=0;
            }
            if(b[no]==1){
                if(va<a[no]){
                    a[no]=va;
                    coulai[no]=0;
                }
            }
        }
        for(int i=1;i<=k;i++){
            if(bb[i]==0){
                aa[i]=d[i][x]+c[i];
                bb[i]=1;
            }
            if(bb[i]==1){
                aa[i]=min(aa[i],d[i][x]+c[i]);
            }
        }
    }
    for(int i=1;i<=k;i++){
        if(dd[i]==1){
            tmpp=aa[i];
            s1-=tmpp;
        }
    }
    printf("%lld",s1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
