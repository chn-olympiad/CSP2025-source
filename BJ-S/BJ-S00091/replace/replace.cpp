#include<bits/stdc++.h>
using namespace std;
string a[200100],b[200100],l,ll,t[200100],t2[200100];
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        l+=a[i].size()+b[i].size();
    }for(int i=1;i<=q;i++){
        cin>>t[i]>>t2[i];
        ll+=t[i].size()+t2[i].size();
    }
        for(int i=1;i<=q;i++){
            if(t[i].size()!=t2[i].size()){
                cout<<0<<endl;
            }else{
                int cnt=0;
                for(int j=1;j<=n;j++){
                    if(b.Find("b")-a[i].Find("b")+t[i].Find("b")==t2[i].Find("b")){
                        cnt++;
                    }
                }cout<<cnt<<endl;
            }
        }

}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
