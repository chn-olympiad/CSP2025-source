#include <bits/stdc++.h>
using namespace std;

int n,q;
int ad[1000010];
int fad[1000010];
string s1,s2;
string t1,t2;
int findb(string s){
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]=='b'){

        }
    }
}
int main{
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        if(findb(s1)>findb(s2)){
            fad[i]=findb(s1)-findb(s2);
            ad[i]=findb(s2)-findb(s1);
        }else{
            fad[i]=findb(s2)-findb(s1);
            ad[i]=findb(s1)-findb(s2);
        }
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        for(int i=1;i<=n;i++){
            if(findb(t1)>findb(t2)){
                if(fad[i]>findb(t1)-findb(t2))ans++;
            }
            if(findb(t2)>findb(t1)){
                if(ad[i]>findb(t2)-findb(t1))ans++;
            }
        }
        }
    }
    cout<<ans;
}
