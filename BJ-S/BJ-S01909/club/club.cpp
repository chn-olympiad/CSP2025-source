#include<bits/stdc++.h>
using namespace std;

int t,n,a[5][100005],m=0

int tm(int f){
    return max(a[f][1],max(a[f][2],a[f][3]));
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>> t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>> a[1][i]>> a[2][i]>> a[3][i];
            m += max(a[1][i],max(a[2][i],a[3][i]));
        }
        if(n==2){
            cout<< max(a[1][1],max(a[2][1],a[3][1]))+max(a[1][2],max(a[2][2],a[3][2]));
            continue;
        }
        sort(a[1]+1,a[1]+n+1);
        for(int i=1;i<=n/2;i++){
            m-=a[1][i];
        }
        cout<<m;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}
