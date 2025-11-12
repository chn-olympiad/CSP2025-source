#include<bits/stdc++.h>
#define N 100005
using namespace std;
int t,n,a[N][3];
struct node{
    int c,b1,b2,b3,ans;
    friend bool operator< (const node &a,const node &b){
        return a.c>b.c||a.c==b.c&&a.ans<b.ans;
    }node(){}
    node(int _c,int _b1,int _b2,int _b3,int _ans){
        c=_c,b1=_b1,b2=_b2,b3=_b3,ans=_ans;
    }
};priority_queue<node>pq;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i][0]>>a[i][1]>>a[i][2];
        while(!pq.empty())pq.pop();
        for(int i=0;i<3;++i){
            pq.push(node(1,n/2-(i==0),n/2-(i==1),n/2-(i==2),a[1][i]));
        }while(!pq.empty()){
            node top=pq.top();
            pq.pop();
            if(top.c==n){
                cout<<top.ans<<endl;
                break;
            }for(int i=0;i<3;++i){
                if(i==0&&top.b1==0||i==1&&top.b2==0||i==2&&top.b3==0)continue;
                pq.push(node(top.c+1,top.b1-(i==0),top.b2-(i==1),top.b3-(i==2),top.ans+a[top.c+1][i]));
            }
        }
    }return 0;
}