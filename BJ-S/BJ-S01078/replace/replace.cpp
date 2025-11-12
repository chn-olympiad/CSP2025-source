#include<bits/stdc++.h>
using namespace std;
const int P=131;
int n,q;
string s[100001][2];
string t[100001][2];
unsigned long long hash1[100001],hash2[100001];
vector<unsigned long long> ha1[100001],ha2[100001];
unsigned long long pw[5000001];
unsigned long long Hash(int l,int r,int id){
    if(l==0){
        return ha1[id][r];
    }
    return ha1[id][r]-ha1[id][l-1]*pw[r-l+1];
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
        hash1[i]=s[i][1][0],hash2[i]=s[i][2][0];
        int n1=s[i][1].size(),n2=s[i][2].size();
        for(int j=1;j<n1;j++){
            hash1[i]=hash1[i]*P+s[i][1][j];
        }
        for(int j=1;j<n2;j++){
            hash2[i]=hash2[i]*P+s[i][2][j];
        }
    }
    pw[0]=1;
    for(int i=1;i<=5e6;i++){
        pw[i]=pw[i]*2;
    }
    for(int i=1;i<=q;i++){
        cin>>t[i][1]>>t[i][2];
        unsigned long long ans1=t[i][1][0],ans2=t[i][2][0];
        ha1[i].push_back(ans1);
        ha2[i].push_back(ans2);
        int n1=t[i][1].size(),n2=t[i][2].size();
        for(int j=1;j<n1;j++){
            ans1=ans1*P+t[i][1][j];
            ha1[i].push_back(ans1);
        }
        for(int j=1;j<n2;j++){
            ans2=ans2*P+t[i][2][j];
            ha2[i].push_back(ans2);
        }
        int cnt=0;
        for(int k=0;k<t[i][1].size();k++){
            for(int j=1;j<=n;j++){
                /*
                if(j==3){
                    for(int l=k;l<=k+s[j][1].size()-1,i);
                    cout<<Hash(k,k+s[j][1].size()-1,i)<<" "<<hash1[j]<<endl;
                }
                */
                if(k+s[j][1].size()>t[i][1].size()||Hash(k,k+s[j][1].size()-1,i)!=hash1[j]){
                    continue;
                }
                if(ha1[i][n1-1]-hash1[j]*pw[k]+hash2[j]*pw[k]==ha2[i][n2-1]){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}
