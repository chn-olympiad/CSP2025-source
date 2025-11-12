#include<bits/stdc++.h>
using namespace std;
int n,q;
char s1[105][205],s2[105][205];
int main(int argc,char** argv){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        char x[205],y[205],d[205];
        long long ans=0;
        cin>>x>>y;
        int lenx=strlen(x);
        if(lenx!=strlen(y)){
            cout<<"0"<<endl;
            continue;
        }
        for(int p=1;p<=n;p++){
            for(int len=1;len<=lenx;len++){
                if(strlen(s1[p])!=len){
                    continue;
                }
                //cout<<"big"<<" "<<len<<" "<<p<<" "<<endl;
                for(int l=0;l<lenx-len+1;l++){
                    memset(d,0,sizeof(d));
                    for(int i=0;i<lenx;i++){
                        d[i]=x[i];
                    }
                    int r=l+len-1,res=0;
                    //cout<<l<<" "<<r<<endl;
                    for(int k=l;k<=r;k++){
                        //cout<<s1[p][k-l]<<endl;
                        if(d[k]==s1[p][k-l]){
                            //cout<<d[k]<<" "<<s1[p][k]<<endl;
                            res++;
                        }
                    }
                    //cout<<res<<endl;
                    if(res==len){
                        for(int k=l;k<=r;k++){
                            d[k]=s2[p][k-l];
                        }
                    }
                    //cout<<d<<" "<<y<<endl;
                    int dis=0;
                    for(int i=0;i<lenx;i++){
                        if(d[i]==y[i]){
                            dis++;
                        }
                    }
                    if(dis==lenx){
                        //cout<<"YES!!!"<<endl;
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
