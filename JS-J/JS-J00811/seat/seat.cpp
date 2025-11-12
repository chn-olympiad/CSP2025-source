#include<bits/stdc++.h>
using namespace std;
int n,m;
int score[1001],sr;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>score[i];
    }
    sr=score[1];
    sort(score+1,score+n*m+1,cmp);
    //for(int i=1;i<=n*m;i++)cout<<score[i]<<" ";
    int x=0,y=1,f=1;
    for(int i=1;i<=n*m;i++){
        x+=f;
        if(x==n+1){
            x=n;
            f=-1;
            y++;
        }
        if(x==0){
            x=1;
            f=1;
            y++;
        }
        if(score[i]==sr){
            cout<<y<<" "<<x<<endl;
            return 0;
        }
    }
    return 0;
}
