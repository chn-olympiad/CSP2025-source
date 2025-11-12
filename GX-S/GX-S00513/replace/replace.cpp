#include<bits/stdc++.h>
using namespace std;
struct rep{
    string s1,s2;
}r[200005];
string q1,q2;
int n,que;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>que;
    for(int i=1;i<=n;i++){
        cin>>r[i].s1>>r[i].s2;
    }
    for(int i=1;i<=que;i++){//i:target string
        long long ans=0;
        cin>>q1>>q2;
        for(int j=1;j<=n;j++){//j:target pair
            for(int k=0;k<q1.length();k++){//k:target start
                bool flag=true;
                for(int l=0;l<r[j].s1.length();l++){//l:compare
                    if(q2[k+l]!=r[j].s2[l]){
                        flag=false;
                        break;
                    }
                    if(q1[k+l]!=r[j].s1[l]){
                        flag=false;
                        break;
                    }
                }
                if(flag==true){
                    bool same=true;
                    for(int l=0;l<k;l++){
                        if(q1[l]!=q2[l]){
                            same=false;
                            break;
                        }
                    }
                    for(int l=k+r[j].s1.length();l<q1.length();l++){
                        if(q1[l]!=q2[l]){
                            same=false;
                            break;
                        }
                    }
                    if(same==true)
                        ans++;
                    //cout<<"replaced "<<r[j].s1<<" "<<r[j].s2<<endl;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
