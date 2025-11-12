#include<bits/stdc++.h>
using namespace std;
int M[1001001][4];
int T,N,ans;
void DFS(int tot,int m1,int m2,int m3,int n1,int n2,int n3){
    if(tot==N+1){
        ans=max(ans,m1+m2+m3);
        return ;
    }
    if(n1<N/2)
        DFS(tot+1,m1+M[tot][1],m2,m3,n1+1,n2,n3);
    if(n2<N/2)
        DFS(tot+1,m1,m2+M[tot][2],m3,n1,n2+1,n3);
    if(n3<N/2)
        DFS(tot+1,m1,m2,m3+M[tot][3],n1,n2,n3+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>N;
        ans=0;
        for(int i=1;i<=N;i++)
            cin>>M[i][1]>>M[i][2]>>M[i][3];
        DFS(1,0,0,0,0,0,0);
        cout<<ans<<endl;
    }
	return 0;
}
