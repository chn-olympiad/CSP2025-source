#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,nm,mn;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    vector<long long>s(m*n);
    for(int i=0;i<m*n;i++){
        cin>>s[i];
    }
    nm=s[0];
    sort(s.begin(),s.end());
    for(int i=0;i<m*n;i++){
        if(s[i]==nm){
            mn=i;
        }
    }
    int c,r;
    for(int i=1;i<=m;i++){
        if(n*i>mn&&n*(i-1)<mn){
            c=i;
            if(n*i/m==0){
                r=n*i;
            }
            else{
                r=n*i-mn;
            }
            cout<<c<<" "<<r+1;
        }
    }
}
