#include<bits/stdc++.h>
using namespace std;
string a1[209000],a2[209000],b1[209000],b2[209000];
int fixq[209000],bugq[209000],ans[209000];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a1[i]>>a2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>b1[i]>>b2[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<a1[i].size();j++){
            if(a1[i][j]!=a2[i][j]){
                fixq[i]++;
            }
        }
    }
    for(int i=1;i<=q;i++){
        for(int j=0;j<b1[i].size();j++){
            if(b1[i][j]!=b2[i][j]){
                bugq[i]++;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=q;j++){
            if(fixq[i]!=bugq[j]){
                continue;
            }
            int num=0;
            for(int o=0;o<b1[j].size();o++){
                if(a1[i][num]==b1[j][o]&&a2[i][num]==b2[j][o]){
                    num++;
                }else{
                    num=0;
                }
                if(num>=a1[i].size()){
                    ans[j]++;
                    break;

                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
