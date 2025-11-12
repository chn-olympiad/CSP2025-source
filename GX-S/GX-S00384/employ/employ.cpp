#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int nn[1000],c[1000];
bool ss[100];
int n,m,t,sum=0;
int p[1000];
void exam(){
for(int i=1;i<=n;i++){
    if(ss[i]==0||c[i]==0){
        nn[i]=0;
        c[i+1]--;
    }
}
}
void choise(){
for(int i=1;i<=n;i++){
        sum+=nn[i];
        if(sum<sum-nn[i]) {
        sum-=nn[i];
    }
        else{
            sum+=nn[i];
            p[i]=nn[i];
        }
}
if(sizeof(p)<m) {choise();}
}
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
memset(p,0,sizeof(p));
memset(nn,1,sizeof(nn));
cin>>n>>m;
int s,t=1;
cin>>s;
for(int i=1;i<=n;i++)
    cin>>c[i];
sort(c,c+1);
for(int i=1;i<=t;i++){
    ss[i]=s%10;
    t++;
    s%=10;
}
exam();
choise();
for(int i=1;i<=n;i++){
    int pp;
    pp+=p[i];
    if(pp==m){
        t++;
    }
}
cout<<t;
fclose(stdin);
fclose(stdout);
return 0;
}
