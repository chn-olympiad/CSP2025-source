#include<bits/stdc++.h>
using namespace std;
struct Node{
    int x,y;
};

int n,m,start,cnt;
int a[100+10];
Node s[100+10];
int d[2+2]={1,-1};
bool cmp(char a,char b){
    if(a>b)return 1;
    else return 0;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    start=a[0];
    sort(a,a+n*m,cmp);
    s[0]=(Node){0,0};
    if(a[0]==start)cout<<"1 1"<<endl;
    else for(int i=1;i<n*m;i++){
        if(s[i-1].x + d[cnt] >=n){
            s[i].x=s[i-1].x;
            s[i].y=s[i-1].y+1;
            cnt++;
        }else if(s[i-1].x + d[cnt] < 0){
            s[i].x=s[i-1].x;
            s[i].y=s[i-1].y+1;
            cnt++;
        }else{
            s[i].x=s[i-1].x+d[cnt];
            s[i].y=s[i-1].y;
        }
        if(a[i]==start){
            cout<<s[i].y+1<<' '<<s[i].x+1<<endl;
            break;
        }
        cnt%=2;
    }
    return 0;
}