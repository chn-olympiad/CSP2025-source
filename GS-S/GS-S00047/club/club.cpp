#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,s = 0,mx = INT_MIN,b;
        cin>>n;
        int a[n][3],com[3] = {0,0,0};
        for(int i=0;i<n;i++)
            for(int j=0;j<3;j++)
                cin>>a[i][j];
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                if(com[j]<=(n/2)){
                    if(a[i][j]>mx) mx = a[i][j];
                    b = j;
                }
                else{
                    j++;
                }
            }
            if(com[b]<=(n/2)){
                s+=mx;
                com[b]++;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
