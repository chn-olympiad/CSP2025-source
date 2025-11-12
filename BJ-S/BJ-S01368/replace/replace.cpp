//3.1
#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<string,string> m;
ll an,aq,al,ans;
string as,bs,ax,ay,az,s1,s2;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>an>>aq;
    for(ll i = 1;i <= an;i++){
        cin>>s1>>s2;
        m[s1] = s2;
    }
    for(ll i = 1;i <= aq;i++){
        //chushihua
        cin>>as>>bs;
        al = as.size();
        ax = "";
        ans = 0;
        if(al != bs.size()){
            cout<<0<<endl;
            continue;
        }
        for(ll i = 0;i < al;i++){
            ay = "";
            if(i > 0){
                ax += as[i-1];
            }
            for(ll j = i;j < al;j++){
                ay += as[j];
                az = "";
                for(int k = j+1;k < al;k++){
                    az += as[k];
                }
                if(m[ay] == ""){
                    continue;
                }
                string str1 = ax+m[ay]+az;
                //cout<<"ax:"<<ax<<" ay:"<<ay<<" az:"<<az<<" str1:"<<str1<<endl;
                if(str1 == bs){
                    ans++;
                }
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
