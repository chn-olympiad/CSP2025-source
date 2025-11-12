#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int ans=0;
    vector<int> s;
    cin>>a;
    int n=a.size();
    for (int i=0;i<n;i++){
        if (a[i]<'a'){
            int m=a[i]-'0';
            s.push_back(m);
        }
    }
    sort(s.begin(),s.begin()+n-1);
    for (int i=n-1;i>=0;i--){
        ans = ans*10+s[i];

    }
    cout<<ans;

    return 0;
}
