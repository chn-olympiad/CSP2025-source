#include <bits/stdc++.h>
using namespace std;

int main()
{freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
long long n,m=0,f=0;
cin >> n;
int a[n];
for (int i=1;i<=n;i++)
{
    cin >> a[i];
}
for(int i=0;i<=n;i++)
{m+=a[i];
}
for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
        for(int k=0;k<=n;k++){int g=max(a[i],a[i+1]);
            if(m>g) f+=1;
        }
    }
}
cout << f;
    return 0;
}
