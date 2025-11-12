#include<bits/stdc++.h>
using namespace std;
int n;
int q;
map<string,string> mp;
string s1;
string s2;
string t1;
string t2;
string x;
string y;
string z;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        mp[s1]=s2;
    }
    while(q--){
        int ans=0;
        cin>>t1>>t2;
        int len1=t1.size();
        int len2=t2.size();
        if(len1!=len2){
            cout<<"0\n";
        }else{
            for(int l=0;l<len1;l++){
                for(int r=l;r<len1;r++){
                    x="";
                    y="";
                    z="";
                    for(int i=0;i<l;i++){
                        x+=t1[i];
                    }
                    for(int i=l;i<=r;i++){
                        y+=t1[i];
                    }
                    for(int i=r+1;i<len1;i++){
                        z+=t1[i];
                    }
                    if(mp.count(y)){
                        y=mp[y];
                    }
                    string s3=x+y+z;
                    if(s3==t2){
                        ans++;
                    }
                }
            }
            cout<<ans<<"\n";
        }

    }
    return 0;
}
