#include<bits/stdc++.h>
using namespace std;
string a,b;
unsigned long long t[200005];
int len[200005];
int n,q;
unsigned long long Hash[5000005];
unsigned long long Base[5000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    Base[0]=1;
    for(int i=1;i<=5000000;i++){
        Base[i]=Base[i-1]*37*37;
    }
    for(int i=1;i<=n;i++){
        cin>>a>>b;
      //  cout<<a<<" "<<b<<endl;
        len[i]=a.size();
        for(int j=0;j<a.size();j++){
            t[i]=t[i]*37+a[j]-'a';
            t[i]=t[i]*37+b[j]-'a';
          //  cout<<t[i]<<" ";
        }
    //    cout<<"asdf"<<endl;
    }
    for(int i=1;i<=q;i++){
        cin>>a>>b;
      //  cout<<a<<" "<<b<<endl;
        int l,r;
        for(int j=0;j<a.size();j++){
            if(a[j]!=b[j]){
                l=j;
                break;
            }
        }
        for(int j=a.size()-1;j>=0;j--){
            if(a[j]!=b[j]){
                r=j;
                break;
            }
        }
        Hash[0]=0;
        for(int j=0;j<a.size();j++){
            if(j!=0)Hash[j]=Hash[j-1];
            Hash[j]=Hash[j]*37+a[j]-'a';
            Hash[j]=Hash[j]*37+b[j]-'a';
            //cout<<Hash[j]<<" ";
        }
       // cout<<endl;
        //cout<<Hash[a.size()-1]<<endl;
      //  cout<<l<<" "<<r<<endl;
        int ans=0;
        for(int j=1;j<=n;j++){
            if(len[j]<r-l+1)continue;
            for(int ll=max(r-len[j]+1,0);ll<=l;ll++){
                int rr=ll+len[j]-1;
                if(rr>=a.size())break;
                //cout<<ll<<" "<<rr<<endl;
                unsigned long long  tt;
                tt=Hash[rr];
               // cout<<rr-ll+1<<"dfgd"<<Base[rr-ll+1]<<endl;
                if(ll!=0){
                    tt-=Hash[ll-1]*Base[rr-ll+1];
                }
              //  cout<<tt<<" "<<t[i]<<endl;
                if(t[j]==tt)ans++;
            }
        }
        cout<<ans<<"\n";
    }
}
