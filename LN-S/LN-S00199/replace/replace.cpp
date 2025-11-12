#include<bits/stdc++.h>
using namespace std;
struct str{
    string a;
    string b;
    int ab;
    int bb;
    int la;
    int lb;
    int c;
}x[200002];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>x[i].a>>x[i].b;
        x[i].la=x[i].a.size();
        x[i].lb=x[i].b.size();
        for(int j=0;j<x[i].la;j++){
            if(x[i].a[j]=='b'){
                x[i].ab=j;
                break;
            }
        }
        for(int j=0;j<x[i].la;j++){
            if(x[i].b[j]=='b'){
                x[i].bb=j;
                break;
            }
        }
        x[i].c=x[i].ab-x[i].bb;
        //  cout<<x[i].ab<<" "<<x[i].bb<<endl;
    }
    string qa;
    string qb;
    int lqa;
    int lqb;
    int qab;
    int qbb;
    int ans=0;
    for(int i=1;i<=q;i++){
        ans=0;
        cin>>qa;
        cin>>qb;
        lqa=qa.size();
        lqb=qb.size();
        if(lqa!=lqb){
            cout<<"0"<<'\n';
            continue;
        }
        for(int j=0;j<lqa;j++){
            if(qa[j]=='b'){
                qab=j;
                break;
            }
        }
        for(int j=0;j<lqb;j++){
            if(qb[j]=='b'){
                qbb=j;
                break;
            }
        }
        for(int j=1;j<=n;j++){
            if(qab-qbb==x[j].c&&x[j].la<=lqa&&qab>=x[j].ab&&(lqb-qbb)>=(x[j].lb-x[j].bb)){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    cout<<endl;
    return 0;
}
