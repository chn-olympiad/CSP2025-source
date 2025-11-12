#include <bits/stdc++.h>
using namespace std;
void dbx(int &n,vector<int> &mg,vector<bool> &is){
    for(int i=0;i<mg.size();i++){
        if(!is[i]){
            for(int j=0;j<=i;j++){
                is[j]=1;
            }
            dbx(n,mg,is);
            int m=0,ma=0,s=0;
            for(int j=0;j<mg.size();j++){
                if(is[j]){
                    m+=mg[j];
                    ma=max(ma,mg[j]);
                    s+=1;
                }
            }
            if(s>=3 && m>2*ma){
                n+=1;
            }
            for(int j=0;j<=i;j++){
                is[j]=0;
            }
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int ans=0;
    int sl;
    cin>>sl;
    vector<int> mg(sl+1,0);
    vector<bool> is(sl+1,0);
    for(int i=0;i<sl;i++){
        cin>>mg[i];
    }
    dbx(ans,mg,is);
    cout<<ans/8<<endl;
    return 0;
}
