#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a_1,Index;
    cin>>n>>m;
    int a[n*m+1];
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    a_1=a[1];
    sort(a+1,a+n*m+1);
    for(int i=m*n;i>=1;i--)
    {
        if(a[i]==a_1)
        {
            Index=m*n-i+1;
            int c=Index%n;
            int d=Index/n;
            if(d%2==1)
            {
                if(c==0) cout<<d<<" "<<n;
                else cout<<d+1<<" "<<n-c+1;
                break;
            }
            else
            {
                if(c==0) cout<<d<<" "<<1;
                else cout<<d+1<<" "<<c;
                break;
            }
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
