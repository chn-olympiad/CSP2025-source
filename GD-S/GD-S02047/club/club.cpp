#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,a[100005][3]={0},m=0,s[100005]={0},ans[5]={0};
    cin>>t;
    cin>>n;
    for(int i=1,i<=n,i++){
        for(int j=1,j<=3,j++){
            cin>>a[i][j];
        }
    }
    for(int i=1,i<=n,i++){
        for(j=1,j<=3,j++){
            ans[j]++;
            if(s[i]<a[i][j]&&ans[j]<=n/2){
                s[i]=a[i][j];
            }
        }
    }
    for(int i=1,i<=n,i++){
        m+=m+s[i]
    }
    cout<<m<<endl;
    return 0
}
