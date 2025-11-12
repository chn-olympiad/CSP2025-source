#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int c,r;
    int v;
};
node M[100];
node N[10][10];
int cnt=1,ans=1;
int j;

bool cmp(node a,node b){
        return a.v>b.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>M[i].v;
        if(i==1){
            j=M[i].v;
        }
    }
    sort(M+1,M+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        M[i].r=cnt;
        M[i].c=ans;
        if(ans%2==1){
            cnt++;
        }
        else{
            cnt--;
        }
        if(cnt>m){
            cnt=m;
            ans++;
        }
        else if(cnt<=0){
            cnt=1;
            ans++;
        }
    }



    for(int i=1;i<=n*m;i++){
        if(M[i].v==j){
           cout<<M[i].c<<" "<<M[i].r;
            exit(0);
        }
    }
    return 0;
}
