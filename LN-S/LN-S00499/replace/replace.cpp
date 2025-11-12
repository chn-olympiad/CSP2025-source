#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
pair<string,string> a[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);;
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    for(int i=1;i<=q;i++){
        string t1,t2;
        cin>>t1>>t2;
        int lt1=t1.length();
        if(t1.length()!=t2.length()){
            cout<<"0\n";
        }else{
            int ans=0;
            for(int j=1;j<=n;j++){
                string s1=a[j].first,s2=a[j].second;
                int l1=s1.size();
                if(t1.find(s1)<=l1){
                    bool flg=0;
                    int pl=t1.find(s1);
                    string now="";
                    for(int k=0;k<lt1;k++){
                        if(k<pl){
                            now+=t1[k];
                        }else if(k>=pl && k<=pl+l1-1){
                            now+=s2[k];
                        }else{
                            now+=t1[k];
                        }
                        if(t2[k]!=now[k]){
                            flg=1;break;
                        }
                    }
                    if(flg==0){ans++;}
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}