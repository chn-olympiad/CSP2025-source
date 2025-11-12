#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,d,e,f,g;
    cin>>n;
    if(n==3){
        cin>>a>>b>>c;
        if(a+b>c&&a+c>b&&b+c>a) cout<<1;
        else cout<<0;
    }
    if(n==4){
        cin>>d,e,f,g;
        int ans=0;
        for(int i = 0;i<1;i++){
           if(d+e+f>g && d+e+g>f && d+f+g>e && e+f+g>d){
            ans ++;
        }
        else if(d+e>f&&d+f>e&&e+f>d){
            ans++;
        }
        else if(d+e>g&&d+g>e&&e+g>d){
            ans ++;
        }
        else if(d+g>f&&d+f>g&&g+f>d){
            ans++;
        }
        else if(g+e>f&&g+f>e&&e+f>g){
            ans++;
        }
        cout<<ans;
        }
    }
    return 0;
}
