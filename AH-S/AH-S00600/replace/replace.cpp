#include<iostream>
#include<cstdio>
using namespace std;
int n,q;
string a,b,s[200005],s2[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        int cnt=0;
        cin>>a>>b;
        if(a.size()!=b.size()){
            cout<<0<<endl;
            continue;
        }
        for(int j=1;j<=n;j++){
            int p=0,ww=a.find(s[j]);
            while(ww!=-1){
                string x=a.substr(0,ww)+s2[j]+a.substr(ww+s[j].size(),a.size()-ww-s[j].size());
                if(x==b){
                    cnt++;
                }
                p=ww+1;
                ww=a.find(s[j],p);
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
return 0;
}
