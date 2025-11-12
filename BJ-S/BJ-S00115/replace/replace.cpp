#include <bits/stdc++.h>
using namespace std;
struct node{
    string s,t;
    int q;
}a[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].t;
        if(a[i].s==a[i].t) a[i].q=1;
        else a[i].q=0;
    }
    while(q--){
        int ans=0;
        string x,y;
        cin>>x>>y;
        if(x.size()!=y.size()){
            cout<<0<<"\n";
            continue;
        }
        int sl=-1,sr=-1;
        int len=x.size();
        for(int i=0;i<len;i++){
            if(x[i]!=y[i]){
                sl=i;
                break;
            }
        }
        for(int i=len-1;i>=0;i--){
            if(x[i]!=y[i]){
                sr=i;
                break;
            }
        }
        for(int i=1;i<=n;i++){
                int slen=a[i].s.size();
            if(slen<sr-sl+1){
                continue;
            }
            for(int j=0;j<len;j++){
                if(x[j]==a[i].s[0]){
                    //cout<<i<<" "<<j<<endl;
                    int flag=1,pt=0;
                    for(int k=j;k<j+slen;k++){
                        if(k>=len) flag=0;
                        if(a[i].s[pt]!=x[k]||a[i].t[pt]!=y[k]){
                            //cout<<a[i].s[pt]<<" "<<x[k]<<" "<<a[i].t[pt]<<" "<<y[k]<<endl;
                            flag=0;
                            break;
                        }
                        pt++;
                    }
                    if(flag==1){
                        if(sl>=j&&sr<=j+slen-1||(sl==-1&&sr==-1&&a[i].q==1)) ans++;
                        //cout<<i<<endl;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
