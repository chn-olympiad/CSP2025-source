#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int cnt;
    vector<int> s(105);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>s[i];
        if(i==0) cnt=s[i];
    }
    sort(s.begin(),s.end());
    for(int i=n;i>0;i++){
        for(int j=m;j>0;j++){
            if(cnt==s[i+j]){
                cout<<i<<" "<<j;
            }
        }
    }
    cout<<endl;
    return 0;
}
