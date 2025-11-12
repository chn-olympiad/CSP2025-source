#include<iostream>
#include<algorithm>
using namespace std;
int a[505];
long long cnt;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
