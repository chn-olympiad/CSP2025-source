#include<bits/stdc++.h>
#define ftsydj 114514
using namespace std;
int cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,i,j=1,a,x,y,s[110];
    cin>>n>>m;
    for(i=1;i<=n*m;++i)cin>>s[i];
    a=s[1];
    sort(s+1,s+n*m+1,cmp);
    while(s[j]!=a)j++;
    x=(j+n-1)/n;
    y=j-n*(x-1);
    if(x%2==0)y=n-y+1;
    cout<<x<<" "<<y<<endl;
    return 0;
}

/*
253099
122934
132668
273528
24856
284856
