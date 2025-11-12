#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[10101];
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int student=a[1];
    sort(a+1,a+n*m+1,cmp);

    int x;
    for(int i=1;i<=n*m;i++){
        if(a[i]==student) x=i;
    }

    int lrousting;

    if(x%n==0) cout<<x/n<<" ",lrousting=x/n;
    else if(x%n!=0) cout<<x/n+1<<" ",lrousting=x/n+1;

    if( lrousting%2==1 ){

        if(x%n!=0) cout<<x%n;
        else if(x%n==0) cout<<n;

    }

    else if( lrousting%2==0 ){

        if(x%n!=0) cout<<n+1-x%n;
        else if(x%n==0) cout<<1;

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
