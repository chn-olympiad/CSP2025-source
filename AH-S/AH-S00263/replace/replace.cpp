#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        s1[i]=" "+s1[i],s2[i]=" "+s2[i];
    }
    while(q--){
        int sum=0;
        string x,y;
        cin>>x>>y;
        x=" "+x,y=" "+y;
        for(int i=1;i<=n;i++){
            int len=s1[i].size()-1;
            string strr=s2[i];
            for(int j=1;j<=x.size();j++){
                string sss=s1[i];
                sss.erase(0,1);
                //cout<<x.substr(j,len)<<" "<<sss;
                if(x.substr(j,len)==sss){
                    string s3=x;
                    for(int k=j;k<=j+len-1;k++){
                        s3[k]=s2[i][k-j+1];
                    }
                    //cout<<" "<<x<<" "<<s3<<" "<<s2[i]<<" "<<j<<" "<<len;
                    if(s3==y){
                        sum++;
                    }
                }
                //cout<<endl;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
