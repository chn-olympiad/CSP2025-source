#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int n,a1[100005],a2[100005],a3[100005];
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a1[j]>>a2[j]>>a3[j];
        }
    }
    int sum=0;
    for(int i=0;i<t;i++){
        for(int j=0;j<n;j++){
            if(a1[j]>a2[j]){
                sum=sum+a1[j];
            }
            if(a2[j]>a1[j]){
                sum=sum+a2[j];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
