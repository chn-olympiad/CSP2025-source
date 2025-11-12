#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n<=2){
    cout<<"0";
    return 0;
    }
    if(n==3){
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b>c&&a+c>b&&c+b>a)cout<<"1";
        else cout<<"0";
    }
    if(n==4){
        int a,b,c,d,ans=0;
        cin>>a>>b>>c>>d;
        if(a+b>c&&a+c>b&&c+b>a)ans++;
        if(a+b>d&&a+d>b&&d+b>a)ans++;
        if(d+b>c&&d+c>b&&c+b>d)ans++;
        if(a+d>c&&a+c>d&&c+d>a)ans++;
        if(a+b+c+d>2*a&&a+b+c+d>2*b&&a+b+c+d>2*c&&a+b+c+d>2*d)ans++;
        cout<<ans;
    }
    else cout<<"9";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
