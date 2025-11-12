#include<bits/stdc++.h>
using namespace std;
int t,rsmx,ans,zf;
struct aa{
    int maxn,id;
}mx[100005];
bool aaa(aa a,aa b){
    int hbs,jl;
    hbs=a.maxn;
    jl=b.maxn;
    return hbs>jl;
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0),cout.tie(0);
cin>>t;
while(t--){
    int mm;
    int rs[3]={0},m[100005][3]={0};
    cin>>mm;
    rs[1]=0,rs[2]=0,rs[3]=0,rsmx=0,ans=0,zf=0;
    for(int i=1;i<=mm;i++){
        cin>>m[i][1]>>m[i][2]>>m[i][3];
        mx[i].maxn=max(max(m[i][1],m[i][2]),m[i][3]);
        if(m[i][1]==mx[i].maxn) mx[i].id=1;
        if(m[i][2]==mx[i].maxn) mx[i].id=2;
        if(m[i][3]==mx[i].maxn) mx[i].id=3;
//        cout<<mx[i]<<endl;
    }
    if(mm==2){
        int gs[6];
        gs[1]=m[1][1]+m[2][2];
        gs[2]=m[1][1]+m[2][3];
        gs[3]=m[1][2]+m[2][1];
        gs[4]=m[1][2]+m[2][3];
        gs[5]=m[1][3]+m[2][1];
        gs[6]=m[1][3]+m[2][2];
        sort(gs+1,gs+6+1);
        cout<<gs[6];
        return 0;
    }
    sort(mx+1,mx+mm+1,aaa);
    for(int i=1;i<=mm;i++){
        if((mx[i].id==1)){
           if(rs[1]<mm/2){
            ans+=mx[i].maxn;
            rs[mx[i].id]++;
            continue;
}
            else if(m[i][2]>m[i][3]){
                ans+=m[i][2];
                rs[2]++;
                 continue;
            }
            else{  ans+=m[i][3];
                  rs[3]++;
                   continue;}}
        if(mx[i].id==2){
           if(rs[2]<mm/2){
            ans+=mx[i].maxn;
            rs[mx[i].id]++;
             continue;
        }
            else if(m[i][1]>m[i][3]){
                ans+=m[i][1];
                rs[1]++;
             continue;
            }
            else{ ans+=m[i][3];
                  rs[3]++;
                   continue;}}
        if(mx[i].id==3){
                if(rs[3]<mm/2){
            ans+=mx[i].maxn;
            rs[mx[i].id]++;
 continue;
        }
            else if(m[i][2]>m[i][1]){
                ans+=m[i][2];
                rs[2]++;
           continue;
            }
            else{  ans+=m[i][1];
                  rs[1]++;
                   continue;}}
    }
cout<<ans<<endl;
}
return 0;
}

/*void dfs(int k,int rsrs){
    rsmx=max(max(rs[1],rs[2]),rs[3]);
    if(rsmx>rsrs/2) return;
    else ans=max(ans,zf);
    for(int i=1;i<=rsrs;i++){
        for(int j=1;j<=3;j++){
            zf+=m[i][j],rs[j]++;
            dfs(k+1,rsrs);
            zf-=m[i][j],rs[j]--;
        }
    }
}*/
