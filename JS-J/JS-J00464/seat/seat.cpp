#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int b[10005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int K=1;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
        if(b[i]>b[1])K++;
    }
    if(K%n==0){
        cout<<K/n<<' ';
        int u=K/n;
        if(u%2==0)cout<<1<<endl;
        if(u%2==1)cout<<n<<endl;
    }
    else{
        cout<<K/n+1<<' ';
        int u=K/n;
        int v=K-u*n;
        if(u%2==0){
            cout<<v<<endl;
        }
        if(u%2==1){
            cout<<n-v+1<<endl;
        }
    }
    return 0;
}
