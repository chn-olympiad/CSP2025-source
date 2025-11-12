#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n,k;
bool mad(){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==1) cnt++;
    }
    if(cnt==n){
        if(k==0){
            cout<<cnt/2<<"\n";
            return 0;
        }
    }

}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.push_back(x);
    }
    mad();
    return 0;
}
