#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int d=1;
    int s[10000];
    int b[10000];
    int c,r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
    }
    int a=s[1];
    sort(s,s+(n*m+1));
    for(int i=n*m;i>=1;i--){
        b[d]=s[i];
        d++;
    }

    for(int i=1;i<=n*m;i++){
        if(b[i]==a){
            if(i<n){
                c=1;
                r=i;
            }
            else if(i>n){
                if(i%n!=0);
                    c=(i/n)+1;
                    if(c%2==0){
                        r=n-(i-(c-1)*n)+1;
                    }
                    else if(c%2!=0){
                        r=i-(c-i)*n;
                    }
            }
        }
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
