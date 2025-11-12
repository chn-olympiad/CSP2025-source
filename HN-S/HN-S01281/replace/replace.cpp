
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct node{
    string s,t;
};
vector<node> a;
//int n;

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int q,n;
    cin>>n>>q;
    a.resize(n);
    for(int i=0;i<n;i++) {
        cin>>a[i].s>>a[i].t;
        //cout<<a[i].s<<' '<<a[i].t<<endl;
    }
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        int len=s1.size();
        int cnt=0;
        int l=0,r=n-1;
        bool flag=false;
        for(int i=0;i<len;i++){
            if(s1[i]!=s2[i]){
                if(!flag) l=i;
                r=i;
                flag=true;
            }
        }
        //cout<<l<<' '<<r<<endl;
        for(int i=0;i<=l;i++){
            for(int k=r+1-i;i+k-1<len;k++){
                string str1=s1.substr(i,k);
                string str2=s2.substr(i,k);
                //cout<<i<<' '<<i+k-1<<endl;
                for(int j=0;j<n;j++){
                    if(a[j].s==str1&&a[j].t==str2) cnt++;
                }
            }
        }
        cout<<cnt<<endl;

    }
}
