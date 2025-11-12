#include<bits/stdc++.h>
using namespace std;
basic_string<int> v;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int t;
            cin>>t;
            if(i==0&&j==0){
                r=t;
            }v.push_back(t);
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    int rk=v.find(r);
    int lie=(rk/m+1),hang;
    if(lie%2==0)hang=n-rk%n;
    else hang=rk%n+1;
    cout<<lie<<" "<<hang;
    fclose(stdin);
    fclose(stdout);
}
