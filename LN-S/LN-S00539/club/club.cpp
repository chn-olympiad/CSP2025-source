#include<bits/stdc++.h>
using namespace std;
int t,n,a[10001],x[10001][10001];
int main(){
    cin>>t;
    while(t--){
        int s=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                cin>>a[j];
            }
            sort(a,a+n,greater<int>());
            for(int j=0;j<3;j++){
                x[a[0]][i]+=x[a[0]][i-1];
                if(x[a[0]][i]==-1) continue;
                x[a[0]][i]++;
                if(x[a[0]][i]>n/2) {
                    x[a[0]][i]=-1;
                    sort(a,a+n,greater<int>());
                    continue;
                }
            }
            s+=a[0];
        }
        cout<<s<<endl;
    }
}
