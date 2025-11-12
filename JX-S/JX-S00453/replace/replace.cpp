#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k;
struct replaced{
    string y1,y2;
};
replaced r[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>r[i].y1>>r[i].y2;
    }
    for(int i=1;i<=k;i++){
        string s1,s2;
        cin>>s1>>s2;
        if(s1.length()!=s2.length()){
            cout<<0<<"\n";
            continue;
        }
        int len=s1.length();
        long long ans=0;
        for(int le=0;le<len;le++){
            for(int ri=0;ri<len;ri++){
                string y="",an_y="";
                for(int j=le;j<=ri;j++){
                    y+=s1[j];
                    an_y+=s2[j];
                }
                if(y==an_y)continue;
                string new_s="";
                for(int j=1;j<=n;j++){
                    if(r[j].y1==y){

                        for(int p=0;p<le;p++)new_s+=s1[p];
                        new_s+=r[j].y2;
                        for(int p=ri+1;p<len;p++)new_s+=s1[p];

                        if(new_s==s2){
                            ans++;
                            new_s="";
                        }
                    }
                }

            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
