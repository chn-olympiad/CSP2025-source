#include<iostream>
#include<cstdio>
using namespace std;
int n;
int Aleph;
int a[5007];
void DFS(int idx,int cnt,int sum,int mx){
    if( idx>n || cnt>n ){
        return ;
    }
    if( cnt>=3 && sum>mx*2 ){
        Aleph++;
    }
    for(int i=idx+1;i<=n;i++){
        DFS(i,cnt+1,sum+a[i],max(mx,a[i]));
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-2;i++){
        DFS(i,i,a[i],a[i]);
    }
    cout<<Aleph;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
