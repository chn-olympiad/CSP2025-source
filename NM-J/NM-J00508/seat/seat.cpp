#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    long long a[n*m];
    long long max=0,j=0,r=0;
    long long b[n*m];
    for(long long i=1;i<=n*m;i++){
        cin >> a[i];
    }
    long long q=0;
    for(long long i=1;i<=n*m;i++){
        for(long long r=1;r<=n*m;r++){
            if(max<=a[r]){
                max=a[r];
                j=r;
            }
        }
        b[i]=max;
        a[j]=-1;
        if(j==1){
            q=i;
        }
        max=0;
    }
    long long l,h;
    l=q/n;
    if(q%n!=0){
        l+=1;
        if(l%2==1){
            h=q%n;
        }else{
            h=n-(q%n-1);
        }
    }else{
        h=n-(q%n);
    }
    cout << l << ' ' << h;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
