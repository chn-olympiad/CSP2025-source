#include<bits/stdc++.h>
using namespace std;
struct data{
	int a,b,c;
}v[1000001];
int n,m,ans,top1,top2,top3,t[1000001];
int pd(){
    int v1=0,v2=0,v3=0;
    for(int i=1;i<=n;i++){
        if(t[i]==1)v1++;
        if(t[i]==2)v2++;
        if(t[i]==3)v3++;
    }if(v1>n/2||v2>n/2||v3>n/2) return 0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(t[i]==1) cnt+=v[i].a;
        if(t[i]==2) cnt+=v[i].b;
        if(t[i]==3) cnt+=v[i].c;
    }
    return cnt;
}
void dfs(int x,int s1,int s2,int s3){
    if(x==n+1){

            ans=max(ans,pd());
        return ;
    }
    if(s1+1<=n/2){
        t[x]=1;
    dfs(x+1,s1+1,s2,s3);
    }
    if(s2+1<=n/2){
        t[x]=2;
    dfs(x+1,s1,s2+1,s3);
    }
    if(s3+1<=n/2){
        t[x]=3;
    dfs(x+1,s1,s2,s3+1);
    }
    t[x]=0;
}
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
	int o;
    cin>>o;
    while(o--){
        ans=0;
        cin>>n;
	for(int i=1;i<=n;i++){
        cin>>v[i].a>>v[i].b>>v[i].c;
	}
	dfs(0,0,0,0);
	cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
