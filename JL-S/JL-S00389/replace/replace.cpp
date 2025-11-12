#include<bits/stdc++.h>
using namespace std;
string a[10050],s[10050];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string la,ls;
        cin>>la>>ls;
        s[i]=ls;
        a[i]=la;
    }
    for(int i=1;i<=q;i++){
        int ans=0;
        string a1,s1;
        cin>>a1>>s1;
        if(a1.size()!=s1.size()){
            cout<<0<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++){
            int k=a[i].size();
            for(int j=0;j<a1.size();j++){
                string temp;
                for(int l=0;l<a1.size();l++){
                    temp[l]=a1[l];
                }
                if(a1[j]==a[i][0]){
                    int flag=0;
                    for(int l=1;l<k;l++){
                        if(a1[j+l]!=a[i][l]){
                            flag=1;
                        }
                    }
                    if(flag==0){
                        for(int l=0;l<k;l++){
                            temp[j+l]=s[i][l];
                        }
                    }
                }
                int cnt=0;
                for(int l=0;l<s1.size();l++){
                    if(temp[l]==s1[l]){
                        cnt++;
                    }
                }
                if(cnt==s1.size()){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
}
