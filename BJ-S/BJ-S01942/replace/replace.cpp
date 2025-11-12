#include<bits/stdc++.h>
using namespace std;
long long n,q,sum;
bool flag;
string s[20010][5],t1,t2,t;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        t=t1;
        if(t1.size()!=t2.size()){
            cout<<0<<endl;
        }
        for(int j=1;j<=n;j++){
            //cout<<"尝试n="<<j<<endl;
            for(int k=0;k<t1.size();k++){
                //cout<<"第"<<k<<"个字符匹配"<<endl;
                for(int l=0;l<s[j][1].size()&&k<t1.size();l++,k++){
                    if(t1[k]!=s[j][1][l]){
                        t=t1;
                        //cout<<"失败"<<l<<endl;
                        break;
                    }
                    t[k]=s[j][2][l];
                    if(l==s[j][1].size()-1){
                        //cout<<"成功"<<endl;
                        flag=1;
                        break;
                    }
                }
                if(flag)    break;
            }
            if(flag){
                if(t==t2){
                    sum++;
                    //cout<<"sum成功++"<<endl;
                }
                flag=0;
                t=t1;
                continue;
            }

        }
        cout<<sum<<endl;
        sum=0;
    }
    return 0;
}
