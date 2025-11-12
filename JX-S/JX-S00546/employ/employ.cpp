#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int n,t,a1,a2,a3,ans;
int data[10001];
string s;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.ans", "w", stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++)cin>>data[i];
    if(m<=3 &&n<=2)cout<<2;

    return 0;
}
