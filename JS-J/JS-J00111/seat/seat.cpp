#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200;
int n,m,t;
int mark[MAXN];
int h,l,r;
bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>mark[i];
    }
    t=mark[0];
    sort(mark,mark+n*m,cmp);
    for(int i=0;i<n*m;i++){
        if(mark[i]==t){
            r=i;
            break;
        }
    }
    l=r/n+1;
    if((r/n)%2==1){
        h=n-r%n;
    }else{
        h=r%n+1;
    }
    cout<<l<<' '<<h<<endl;
    return 0;
}
