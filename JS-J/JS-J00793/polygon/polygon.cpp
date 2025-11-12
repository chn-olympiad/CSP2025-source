#include<bits/stdc++.h>
using namespace std;
string a;
vector<int> s;
int n;
bool cmp(int q1,int q2){
    return q1>q2;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    cout<<n*n-2;
    return 0;
}

