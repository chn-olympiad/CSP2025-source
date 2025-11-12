#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
    string s1,s2;
};

vector <node> s[5000005];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n,_; cin>>n>>_;

    for(int i=1;i<=n;i++){
        string s1,s2; cin>>s1>>s2;
        s[s1.size()].push_back({s1,s2});
    }

    while(_--){
        string s1,s2; cin>>s1>>s2;
        int len; len=s1.size();
        int ans; ans=0;
        int L,R;
        for(int i=0;i<len;i++){
            if(s1[i]!=s2[i]){
                L=i-1;
                break;
            }
        }

        for(int i=len-1;i>=0;i--){
            if(s1[i]!=s2[i]){
                R=i+1;
                break;
            }
        }

        //cout<<"L R: "<<L<<" "<<R<<endl;
        string x; x="";
        for(int i=0;i<=L+1;i++){
            if(i!=0){
                x+=s1[i-1];
            }
            string y; y="";
            for(int j=len-1;j>=R-1;j--){
                if(j!=len-1){
                    y=s1[j+1]+y;
                }
                int findd; findd=len-i-len+j+1;
                //cout<<i<<" "<<j<<" "<<x<<" "<<y<<endl;
                for(int k=0;k<s[findd].size();k++){
                    string chk1; chk1=x+s[findd][k].s1+y;
                    string chk2; chk2=x+s[findd][k].s2+y;

                    //cout<<findd<<endl;
                    //cout<<x<<" "<<s[findd][k].s2<<" "<<y<<" "<<s1<<endl;
                    //cout<<x<<" "<<s[findd][k].s1<<" "<<y<<" "<<s2<<endl;
                    if(chk1==s1 && chk2==s2){
                        ans++;
                    }
                }
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
