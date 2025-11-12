#include<bits/stdc++.h>
using namespace std;
int t,n,cnt,m,anss;
int ss[10],he[10],w[10];
struct node{
    int x,y,z,k;
    int c1,c2;
    int bh,lh,sh;
    int ans;
}s[114514];
bool cmp(node q,node p){
    if(q.k!=p.k) return q.k>p.k;
    else return q.c1>p.c1;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        m=n/2;
        anss=0;
        memset(s,0,sizeof(s));
        memset(ss,0,sizeof(ss));
        memset(he,0,sizeof(he));
        for(int i=1;i<=n;i++){
            cin>>s[i].x>>s[i].y>>s[i].z;
            if(s[i].x>=s[i].y&&s[i].x>=s[i].z){
                ss[1]++;
                he[1]+=s[i].x;
                s[i].bh=1;
                if(s[i].y>=s[i].z){
                    s[i].c1=s[i].x-s[i].y;
                    s[i].c2=s[i].y-s[i].z;
                    s[i].lh=2;
                    s[i].sh=3;
                }
                else{
                    s[i].c1=s[i].x-s[i].z;
                    s[i].c2=s[i].z-s[i].y;
                    s[i].lh=3;
                    s[i].sh=2;
                }
            }
            if(s[i].y>s[i].x&&s[i].y>s[i].z){
                ss[2]++;
                he[2]+=s[i].y;
                s[i].bh=2;
                if(s[i].x>=s[i].z){
                    s[i].c1=s[i].y-s[i].x;
                    s[i].c2=s[i].x-s[i].z;
                    s[i].lh=1;
                    s[i].sh=3;
                }
                else{
                    s[i].c1=s[i].y-s[i].z;
                    s[i].c2=s[i].z-s[i].x;
                    s[i].lh=3;
                    s[i].sh=1;
                }
            }
            if(s[i].z>s[i].y&&s[i].z>s[i].x){
                ss[3]++;
                he[3]+=s[i].z;
                s[i].bh=3;
                if(s[i].y>=s[i].x){
                    s[i].c1=s[i].z-s[i].y;
                    s[i].c2=s[i].y-s[i].x;
                    s[i].lh=2;
                    s[i].sh=1;
                }
                else{
                    s[i].c1=s[i].z-s[i].x;
                    s[i].c2=s[i].x-s[i].y;
                    s[i].lh=1;
                    s[i].sh=2;
                }
            }
        }
        //for(int i=1;i<=n;i++){
         //   cout<<i<<" "<<s[i].x<<" "<<s[i].y<<" "<<s[i].z<<" "<<s[i].bh<<" "<<s[i].lh<<" "<<s[i].sh<<" "<<s[i].c1<<" "<<s[i].c2<<endl;
        //}
        for(int j=1;j<=3;j++){
            //cout<<j<<" "<<anss<<endl;
            if(ss[j]<=m) {
              //  cout<<j<<" "<<ss[j]<<" "<<he[j]<<endl;
             //   cout<<ss[j]<<" "<<m<<" "<<anss<<endl;
                anss+=he[j];
                w[j]=1;
                continue;
            }
            for(int i=1;i<=n;i++){
                if(s[i].bh==j){
                    s[i].k=1;
                }
            }
            sort(s+1,s+n+1,cmp);
            for(int i=1;i<=n;i++) s[i].k=0;
            for(int i=1;i<=m;i++){
                if(j==1) anss+=s[i].x;
                if(j==2) anss+=s[i].y;
                if(j==3) anss+=s[i].z;
            }
           // cout<<j<<" "<<anss<<endl;
            for(int i=m+1;i<=ss[j];i++){
                int temp;
                temp=s[i].lh;
                s[i].lh=s[i].sh;
                s[i].bh=temp;
                ss[temp]++;
                if(i==1) he[temp]+=s[i].x;
                if(i==2) he[temp]+=s[i].y;
                if(i==3) he[temp]+=s[i].z;
                s[i].c1=s[i].c2;

            }
        }
       // cout<<anss<<endl;
       // for(int i=1;i<=n;i++){
         //   if(s[i].ans==1&&w[i]!=1) anss+=s[i].x;
         //   if(s[i].ans==2&&w[i]!=1) anss+=s[i].y;
            //if(s[i].ans==3&&w[i]!=1) anss+=s[i].z;
            //cout<<i<<" "<<s[i].ans<<" "<<anss<<" "<<s[i].x<<" "<<s[i].y<<" "<<s[i].z<<endl;
       // }
        cout<<anss<<endl;
    }

    return 0;
}
