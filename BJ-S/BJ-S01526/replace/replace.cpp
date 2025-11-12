#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005],b[200005];
struct sb{
    string a,b;
};
sb f(sb x){
    if(x.a==x.b)return {"",""};
    int i=0,j=x.a.length()-1;
    while(x.a[i]==x.b[i])i++;
    while(x.a[j]==x.b[j])j--;
    return {
        x.a.substr(i,j-i+1),
        x.b.substr(i,j-i+1)
    };
}
int can(string a,string b,string c,string d){
    int x=0;
    for(int i=0;i<a.length()-c.length()+1;i++){
        string u=a;
        int f=u.find(c,i);
        if(f<0)continue;
        i=f;
        string v=u.replace(f,d.size(),d);
        if(v==b)x++;
    }
    return x;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sb SB=f({a[i],b[i]});
        a[i]=SB.a;
        b[i]=SB.b;
    }
    while(q--){
        string x,y;
        cin>>x>>y;
        int ans=0;
        for(int i=1;i<=n;i++){
            string aa=a[i],bb=b[i];
            int res=can(x,y,aa,bb);
            if(res){
                ans+=res;
                while(i<=n){
                    i++;
                    string cc=a[i],dd=b[i];
                    if(cc==aa&&bb==dd){
                        ans+=res;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
