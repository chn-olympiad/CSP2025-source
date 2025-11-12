#include<bits/stdc++.h>
using namespace std;
map<string,string>s;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    while(n--){
        string a,b;
        cin>>a>>b;
        s[a]=b;
    }
    while(q--){
        string a,b;
        cin>>a>>b;
        int ans=0;
        for(auto [x,y]:s){
            for(int i=0;i<=a.size();i++){
                string left="",mid="",right="";
                for(int j=0;j<i;j++){
                    left+=a[j];
                }
                for(int j=i;j<=i+x.size()-1;j++){
                    mid+=a[j];
                }
                for(int j=i+x.size();j<a.size();j++){
                    right+=a[j];
                }
                //cout<<left<<' '<<mid<<' '<<right<<endl;
                //cout<<left<<' '<<y<<' '<<right<<endl;
                if(mid==x&&left+y+right==b)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
