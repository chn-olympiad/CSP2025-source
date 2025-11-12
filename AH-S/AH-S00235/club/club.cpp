#include<bits/stdc++.h>
using namespace std;
long long ans;
int t,n,x[100001][4],a[50002],b[50002],c[50002],x1[10001][4],ta,tb,tc;
void bbb(int i);
void ccc(int i);
void aaa(int i){
    if(ta>n/2){
        int p=x[i][1],q=i,qq=i,pp=x[i][2],q1=ta,qq1=ta;
        for(int j=1;j<=ta;j++){
            if(x[a[j]][1]>p){
                p=x[a[j]][1];q=a[j];q1=j;
            }
            if(x[a[j]][2]>pp){
                pp=x[a[j]][2];qq=a[j];qq1=j;
            }
        }
        if(p>=pp){
            a[q1]=i;ta--;
            tb++;b[tb]=q;bbb(q);
        }
        else{
            a[qq1]=i;ta--;
            tc++;c[tc]=qq;ccc(qq);
        }
    }
}
void bbb(int i){
    if(tb>n/2){
        int p=-x[i][1],q=i,qq=i,pp=x[i][3],q1=tb,qq1=tb;
        for(int j=1;j<=tb;j++){
            if(-x[b[j]][1]>p){
                p=-x[b[j]][1];q=b[j];q1=j;
            }
            if(x[b[j]][3]>pp){
                pp=x[b[j]][3];qq=b[j];qq1=j;
            }
        }
        if(p>=pp){
            b[q1]=i;tb--;
            ta++;a[ta]=q;aaa(q);
        }
        else{
            b[qq1]=i;tb--;
            tc++;c[tc]=qq;ccc(qq);
        }
    }
}
void ccc(int i){
    if(tc>n/2){
        int p=-x[i][2],q=i,qq=i,pp=-x[i][3],q1=tc,qq1=tc;
        for(int j=1;j<=tc;j++){
            if(-x[c[j]][2]>p){
                p=-x[c[j]][2];q=c[j];q1=j;
            }
            if(-x[c[j]][3]>pp){
                pp=-x[c[j]][3];qq=c[j];qq1=j;
            }
        }
        if(p>=pp){
            c[q1]=i;tc--;
            ta++;a[ta]=q;aaa(q);
        }
        else{
            c[qq1]=i;tc--;
            tb++;b[tb]=qq;bbb(qq);
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    cin>>t;
    for(t;t>=1;t--){
        cin>>n;
        ta=tb=tc=0;ans=0;
        for(int i=1;i<=n;i++){
            cin>>x1[i][1]>>x1[i][2]>>x1[i][3];
            x[i][1]=x1[i][2]-x1[i][1];x[i][2]=x1[i][3]-x1[i][1];x[i][3]=x1[i][3]-x1[i][2];
            if(max(x1[i][1],max(x1[i][2],x1[i][3]))==x1[i][1]){
                ta++;
                a[ta]=i;
                aaa(i);
            }
            else if(max(x1[i][1],max(x1[i][2],x1[i][3]))==x1[i][2]){
                tb++;
                b[tb]=i;
                bbb(i);
            }
            else if(max(x1[i][1],max(x1[i][2],x1[i][3]))==x1[i][3]){
                tc++;
                c[tc]=i;
                ccc(i);
            }
        }
        long long anns=0;
        for(int i=1;i<=ta;i++)anns+=x1[a[i]][1];
        for(int i=1;i<=tb;i++)anns+=x1[b[i]][2];
        for(int i=1;i<=tc;i++)anns+=x1[c[i]][3];
        cout<<anns;
    }
    freopen("club.out","w",stdout);
    return 0;
}
