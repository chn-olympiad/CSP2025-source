//t1simple
#include<iostream>
using namespace std;
const int maxn=1e5+5;
int t;
int n;
int a[maxn][3];
int cnta[3];
int tryi(int num){
    if(num>=n) return 0;
    int maxi=-1e9;
    for(int i=0;i<3;i++){
        if(cnta[i]<n/2){
        cnta[i]++;
        maxi=max(tryi(num+1)+a[num][i],maxi);
        cnta[i]--;
        }
    }
    return maxi;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        bool flaga=1,flagb=1,flagc=1;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<3;i++){
            cnta[i]=0;
        }
        cout<<tryi(0)<<endl;
    }
    return 0;
}
