#include<bits/stdc++.h>
using namespace std;

const int N=105,M=105;
int n,m,a1;
int a[N*M];

bool cmp(int a,int b){
    return a>=b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;++i)cin>>a[i];
    a1=a[0];
    sort(a,a+n*m,cmp);
    int idx;
    for(idx=0;idx<n*m&&a[idx]!=a1;++idx);
    cout<<idx/n+1<<" "<<(idx/n%2==0?idx%n+1:n-((idx%n+1)-1));
    return 0;
}