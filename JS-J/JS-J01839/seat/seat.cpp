#include<bits/stdc++.h>
using namespace std;
int n,m,s[110],p,r;
vector<int> a;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int z=n*m;
    int st[n+1][m+1];
    for (int i=1;i<=z;i++){
        cin>>p;

        a.push_back(p);
    }
    r=a[0];
    cout<<r<<endl;
    sort(a.begin(),a.begin()+z+1);

    int i=1,j=1,c=1;
    while(c<=z){
        if(a[z-c+1]==r) cout<<j<<' '<<i;
        st[i][j]=a[z-c+1];

        if(c%n==0) {j++;}
        else if(j%2==0) {i--;}
        else {i++;}

        c++;

    }
    return 0;
}
