#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n=s.size();
    vector<int> a(n,0);
    int i=0;
    int b;


    for(int j=0;j<n;j++){
        if(s[j]<='9'){
            char c=s[j];
            b=c-'0';
            a[i]=b;
            i++;
        }
    }
    vector<int> aa(i,0);
    for(int j=0;j<i;j++)aa[j]=a[j];
    sort(aa.begin(),aa.end());
    for(int j=i-1;j>=0;j--){
        cout<<aa[j];
    }
    return 0;
}
