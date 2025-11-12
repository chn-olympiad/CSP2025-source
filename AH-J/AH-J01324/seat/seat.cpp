#include <bits/stdc++.h>
using namespace std;
int a[105];
int x,c;

int main ()
{
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
    int n,m;
    cin >>n>>m;
    int k=n*m;
    for (int i=1;i<=k;i++){
        int t;
        cin >>t;
        a[i]=t;
        if (i==1) x=t;
    }
    sort (a+1,a+1+n*m,greater<int>());
    for (int i=1;i<=k;i++){
        if (a[i]==x)c=i;
    }
    int b=1,pm=0;
    for (int j=1;j<=m;j++){
         if (b==1){
            for (int i=1;i<=n;i++){
                pm++;
                if (pm==c) cout <<j<<" "<<i;
            }
            b=0;
         }else {
             for (int i=n;i>=1;i--){
                pm++;
                if (pm==c) cout <<j<<" "<<i;
             }
             b=1;
         }
    }
    //CCF dadadeyaoxi
	return 0;
}
