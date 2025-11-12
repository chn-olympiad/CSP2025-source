#include<bits/stdc++.h>
using namespace std;
int n,m,dp[2003][2001],o[2001][2001];
map<string,string>p;
vector<char> v[24];
bool check(string a,int dep){
    int l=v[a[dep-1]-'a'].size();
    for(int i=0;i<=l;i++){
        if(v[a[dep-1]-'a'][i]==a[dep]){
            return check(a,dep+1);
        }
    }
    return 0;
}
string oo(string a,int x,int y){
    string b;
    for(int i=x;i<=y;i++){
        b+=a[i];
    }
    return b;
}
int main(){
    freopen("replace1.in","r",stdin);
    freopen("replace1.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string a1,a2;
        cin>>a1>>a2;
        p[a1]=a2;
        int l=a1.size();
        for(int j=2;j<=l;j++){
            string s;
            s+=a1[j-1];
            s+=a1[j];
            if(!check(s,0))
            v[a1[j-1]-'a'].push_back(a1[j]);
        }
    }
    cout<<1;
    while(m--){
        string a,b;
        cin>>a>>b;
        int l=a.size();
        for(int j=0;j<l;j++){
            for(int i=1;i<=l;i++){
                string c=oo(a,i,i+j),d=oo(b,i,i+j);
                if(check(c,0)&&p[c]==d){
                    o[i][i+j]=1;
                    dp[i][i+j]=1;
                }
                else {
                    o[i][i+j]=0;
                    dp[i][i+j]=0;
                }
                for(int k=i+1;k<=i+j;k++){
                    if(o[i][k-1]&&o[k][i+j]){
                        dp[i][i+j]+=dp[i][k-1]+dp[k][i+j];
                    }
                }
            }
        }
        cout<<dp[1][l]<<endl;
    }
}
