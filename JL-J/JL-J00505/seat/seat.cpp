#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int cnt[10005];
int n,m;
void search(int x,int y,int fw,int k,int p,bool s){
    a[x][y]=cnt[k];
    if(a[x][y]==p){
        cout<<y<<" "<<x<<endl;
        return;
    }
    if((x==1||x==n)&&s){
        if(fw==1){
            fw=2;
        }else{
            fw=1;
        }
        y++;
        s=false;
    }else{
        if(fw==1){
            x--;
        }else{
            x++;
        }
        s=true;
    }
    search(x,y,fw,k+1,p,s);
    return;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k,s=n*m;
    cin>>cnt[1];
    k=cnt[1];
    for(int i=2;i<=s;i++){
        cin>>cnt[i];
    }
    sort(cnt+1,cnt+s+1,greater<int>());
    search(1,1,2,1,k,0);
    return 0;
}
