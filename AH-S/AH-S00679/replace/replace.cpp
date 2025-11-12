#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int n,t;
string a[200005],b[200005];
int x=10;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    //cout<<endl;
    while(t--){
        int ans=0;
        string x,y;
        cin>>x>>y;
        if(x.size()!=y.size()){
            cout<<0<<endl;
        }else{
            for(int i=1;i<=n;i++){
                if(x.find(a[i])==-1||y.find(b[i])==-1) continue;
                int pos=0;
                while(true){
                    if(x.find(a[i],pos)==-1) break;
                    if(y.find(b[i],pos)==-1) break;
                    if(x.find(a[i],pos)==y.find(b[i],pos)){
                        int pos1=x.find(a[i],pos);
                        if(x.substr(0,pos1)==y.substr(0,pos1)&&x.substr(pos1+a[i].size(),x.size()-pos1-a[i].size())==y.substr(pos1+b[i].size(),y.size()-pos1-b[i].size())){
                            ans++;
                            break;
                        }
                    }
                    pos=x.find(a[i],pos)+1;
                }
            }
            cout<<ans<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
