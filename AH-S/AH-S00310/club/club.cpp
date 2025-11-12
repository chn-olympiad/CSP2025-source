#include<bits/stdc++.h>
using namespace std;
long long  a[100010][100010];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int n,t;
cin>>t;
while(t--){
    cin>>n;
    int t[4];
    int nm=0;
    for(int i=1;i<=n;i++){
        int maxn=0,maxnn=0;
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
        for(int j=1;j<=3;j++){
            if(t[j]+1<=n/2){
                if(maxn<a[i][j]){
                    maxn=a[i][j];
                    maxnn=j;
                }
            }
        }
        nm=nm+maxn;
        t[maxnn]++;

     }
     cout<<nm<<endl;
    }
return 0;
}
