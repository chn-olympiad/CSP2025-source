#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200001],s2[200001],t1[200001],t2[200001];
string x,z;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>t1[i]>>t2[i];
        int ans=0;
        if(t1[i].length()!=t2[i].length()){
            ans=0;
        }else{
           for(int j=1;j<=n;j++){
                if(s1[j].length()==t1[i].length()){
                    if(s1[j]==t1[i]&&s2[j]==t2[i]){
                        ans++;
                    }
                }else{
                    int flag=0,e=0;
                    for(int k=0;k<t1[i].length();k++){
                        x=t1[i][k];
                        z=t2[i][k];
                        if(x!=z){
                           for(int f=k;f<k+s1[j].length();f++){
                                if(t1[i][f]!=s1[j][f-k]||t2[i][f]!=s2[j][f-k]){
                                    flag++;
                                    break;
                                }
                           }
                           e=k+s1[j].length();
                           break;
                        }else if(k==t1[i].length()-1){
                            flag++;
                        }
                    }
                    if(flag==0){
                        for(int k=e;k<t1[i].length();k++){
                            if(t1[i][k]!=t2[i][k]){
                                flag++;
                                break;
                            }
                        }
                    }
                    if(flag==0){
                        ans++;
                    }
                 //   cout<<ans<<endl;
               }
           }
        }
        cout<<ans<<endl;
    }

    return 0;
}
