#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
};
struct node1{
    int yx,x;
    int i;
    friend bool operator<(node1 a,node1 b){
        return a.yx>b.yx;
    }
};
int n;
node s[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
        }
        unsigned long long ans=0;
        priority_queue<node1> a,b,c;
        for(int i=1;i<=n;i++){
            if(s[i].a>s[i].b&&s[i].a>s[i].c){
                int p;
                p=s[i].a-max(s[i].b,s[i].c);
                if(a.size()<n/2){
                    a.push({p,s[i].a,i});
                }
                else{
                    node1 r=a.top();
                    if(r.yx<p){
                        ans+=r.x-r.yx;
                        a.pop();
                        a.push({p,s[i].a,i});
                    }
                    else {
                        ans+=s[i].a-p;
                    }
                }
            }
            else if(s[i].b>s[i].a&&s[i].b>s[i].c){
                int p;
                p=s[i].a-max(s[i].b,s[i].c);
                if(b.size()<n/2){
                    b.push({p,s[i].b,i});
                }
                else{
                    node1 r=b.top();
                    if(r.yx<p){
                        ans+=r.x-r.yx;
                        b.pop();
                        b.push({p,s[i].b,i});
                    }
                    else {
                        ans+=s[i].b-p;
                    }
                }
            }
            else {
                int p;
                p=s[i].a-max(s[i].b,s[i].c);
                if(c.size()<n/2){
                    c.push({p,s[i].c,i});
                }
                else{
                    node1 r=c.top();
                    if(r.yx<p){
                        ans+=r.x-r.yx;
                        c.pop();
                        c.push({p,s[i].c,i});
                    }
                    else {
                        ans+=s[i].c-p;
                    }
                }
            }
        }
        while(a.size()){
            node1 r=a.top();
            ans+=r.x;
            a.pop();
        }
        while(b.size()){
            node1 r=b.top();
            ans+=r.x;
            b.pop();
        }
        while(c.size()){
            node1 r=c.top();
            ans+=r.x;
            c.pop();
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
