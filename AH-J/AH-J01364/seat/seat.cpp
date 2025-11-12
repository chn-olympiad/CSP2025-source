#include<bits/stdc++.h>
using namespace std;
int n,m,k,d=1;
int a[300],s[200][200];
bool cmp(int x,int y){return x>y;}
void func(bool pd,int x){
    if(pd)for(int i=1;i<=n;i++)
        s[i][x]=a[d++];
    else for(int i=n;i>=1;i--)
        s[i][x]=a[d++];
    if(x==m)return;
    func(!pd,x+1);
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    k=a[1];
    sort(a+1,a+n*m+1,cmp);
    func(1,1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]==k){
                cout<<j<<" "<<i;
                return 0;
            }
	return 0;
}
