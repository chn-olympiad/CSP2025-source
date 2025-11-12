#include <bits/stdc++.h>
using namespace std;
string s1[10001],s2[10001],t1[10001],t2[10001];
int n,q,ans,p1,p2,w1,w2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    if(n<=100&&q<=100){
        for(int i=1;i<=q;i++){
                ans=0;
            cin>>t1[i]>>t2[i];
            for(int j=1;j<=n;j++){
                for(int k=0;k<t1[i].size();k++){
                    if(t1[i][k]==s1[j][0]){
                        string s3=t1[i];
                        for(int h=0;h<s1[j].size();h++){
                            if(s3[k+h]==s1[j][h]) s3[k+h]=s2[j][h];
                            else break;
                        }
                        if(s3==t2[i]){
                            ans++;
                            break;
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    else{
        for(int i=1;i<=q;i++){
            ans=0;
            cin>>t1[i]>>t2[i];
            p1=t1[i].find("b"),p2=t2[i].find("b");
            for(int j=1;j<=n;j++){
                w1=s1[j].find("b"),w2=s2[j].find("b");
                if(w1>=p1&&w2>=p2&&s1[j].length()-w1>=t1[i].length()-p1&&s2[j].length()-w2>=t2[i].length()-p2)
                    ans++;
            }
        cout<<ans<<endl;
        }
    }
    return 0;
}
