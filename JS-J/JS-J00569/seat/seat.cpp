#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[14][14];
int s[114];

bool cmp(int a,int b){
    if(a>b)
      return a>b;
    else
      return b<a;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>s[i];

    int num=s[1];
    sort(s+1,s+n*m+1,cmp);

    int x=1;
    int is=2;
    for(int i=1;i<=m;i++){
       for(int j=x;j<=x+n-1;j++){
          if(is%2==0){
            a[j-x+1][i]=j;
          }
          else{
            a[n-j+x][i]=j;
          }
       }

       is++;
       x+=n;
    }

    int pos=0;
    for(int i=1;i<=n*m;i++){
        if(s[i]==num)
          pos=i;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==pos){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }

    return 0;
}
