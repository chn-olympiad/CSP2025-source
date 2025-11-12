#include<bits/stdc++.h>
using namespace std;
int n,m,pos1;
string a[200005],b[200005],s,t;
string x(string s,string a,string b,int pos){
    for(int i=pos;i<s.size();i++){
        int j=0,t=i;
        while(j<a.size()&&i<s.size()&&s[i]==a[j])
            i++,j++;
        if(j==a.size()){
            s.replace(t,a.size(),b);
            pos1=t+1;
            return s;
        }
    }
    return "-";
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    for(int i=1;i<=m;i++){
        cin>>s>>t;
        int ans=0;
        for(int i=1;i<=n;i++){
            string _;
            pos1=0;
            while(_[0]!='-'){
                _=s;
                _=x(_,a[i],b[i],pos1);
                if(_==t){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
