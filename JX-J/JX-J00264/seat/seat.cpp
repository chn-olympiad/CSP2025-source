#include<bits/stdc++.h>
using namespace std;
int n,m,ls[110];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>ls[i];
    int r = ls[1];
    sort(ls+1,ls+1+n*m,cmp);
    int i;
    for(i=1;i<=n*m;i++)
        if(ls[i]==r)
            break;
    int x,y;
    if(i%m==0)
        x = i/m;
    else if(i<m)
        x = 1;
    else
        x = i/m+1;
    if(x%2)
        y = i%m?i%m:m;
    else
        y = m-i%m+1;
    cout<<x<<' '<<y<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
