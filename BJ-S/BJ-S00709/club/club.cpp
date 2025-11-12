#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
struct str{
    int a,b,c;
}a[100010];
bool cmp(const str &x,const str &y){
    //return max({x.a,x.b,x.c})>max({y.a,y.b,y.c});
    return x.a-x.b>y.a-y.b;

    if(x.a-max(x.b,x.c)!=y.a-max(y.b,y.c)){
        return x.a-max(x.b,x.c)>y.a-max(y.b,y.c);
    }
    else if(x.b-x.c!=y.b-y.c){
        return x.b-x.c>y.b-y.c;
    }
    else if(x.c!=y.c){
        return x.c>y.c;
    }
    else if(x.b!=y.b){
        return x.b>y.b;
    }
    return x.a>y.a;
}
struct scmp{
    int cur,a1,a2;
    bool operator <(const scmp &X) const{
        if(cur-max(a1,a2)!=X.cur-max(X.a1,X.a2)){
            return cur-max(a1,a2)<X.cur-max(X.a1,X.a2);
        }
        else if(a1-a2!=X.a1-X.a2){
            return a1-a2<X.a1-X.a2;
        }
        else if(a2!=X.a2){
            return a2<X.a2;
        }
        else if(a1!=X.a1){
            return a1<X.a1;
        }
        return cur<X.cur;
    }
};
struct scmptmp{
    int cur,ot;
    bool operator <(const scmptmp &X) const{
        return (cur-ot!=X.cur-X.ot?cur-ot<X.cur-X.ot:(cur!=X.cur?cur<X.cur:ot<X.ot));
    }
};
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i].a >> a[i].b >> a[i].c;
        }
        sort(a+1,a+1+n,cmp);
        int ans=0;
        multiset<scmp> s1,s2,s3;
        for(int i=1;i<=n;i++){
            if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
                if(s1.size()<n/2){
                    s1.insert({a[i].a,a[i].b,a[i].c});
                    ans+=a[i].a;
                }
                else{
                    auto tmp=*s1.begin();
                    if(tmp.cur+max(a[i].b,a[i].c)<a[i].a+max(tmp.a1,tmp.a2)){
                        if(tmp.a1>tmp.a2){
                            s1.erase(s1.find(tmp));
                            ans-=tmp.cur;
                            ans+=tmp.a1;
                            s2.insert({tmp.a1,tmp.cur,tmp.a2});
                            ans+=a[i].a;
                        }
                        else{
                            s1.erase(s1.find(tmp));
                            ans-=tmp.cur;
                            ans+=tmp.a2;
                            s3.insert({tmp.a2,tmp.cur,tmp.a1});
                            ans+=a[i].a;
                        }
                        s1.insert({a[i].a,a[i].b,a[i].c});
                    }
                    else{
                        if(a[i].b>a[i].c){
                            s2.insert({a[i].b,a[i].a,a[i].c});
                            ans+=a[i].b;
                        }
                        else{
                            s3.insert({a[i].c,a[i].a,a[i].b});
                            ans+=a[i].c;
                        }
                    }
                }
            }
            else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
                if(s2.size()<n/2){
                    s2.insert({a[i].b,a[i].a,a[i].c});
                    ans+=a[i].b;
                }
                else{
                    auto tmp=*s2.begin();
                    if(tmp.cur+max(a[i].a,a[i].c)<a[i].b+max(tmp.a1,tmp.a2)){
                        if(tmp.a1>tmp.a2){
                            s2.erase(s2.find(tmp));
                            ans-=tmp.cur;
                            //cerr << i << " ans-= " << tmp.cur << endl;
                            ans+=tmp.a1;
                            //cerr << i << " ans+= " << tmp.a1 << endl;
                            s1.insert({tmp.a1,tmp.cur,tmp.a2});
                            ans+=a[i].b;
                            //cerr << i << " ans+= " << a[i].b << endl;
                        }
                        else{
                            s2.erase(s2.find(tmp));
                            ans-=tmp.cur;
                            //cerr << i << " ans-= " << tmp.cur << endl;
                            ans+=tmp.a2;
                            //cerr << i << " ans+= " << tmp.a2 << endl;
                            s3.insert({tmp.a2,tmp.a1,tmp.cur});
                            ans+=a[i].b;
                            //cerr << i << " ans+= " << a[i].b << endl;
                        }
                        s2.insert({a[i].b,a[i].a,a[i].c});
                    }
                    else{
                        if(a[i].a>a[i].c){
                            s1.insert({a[i].a,a[i].b,a[i].c});
                            ans+=a[i].a;
                        }
                        else{
                            s3.insert({a[i].c,a[i].a,a[i].b});
                            ans+=a[i].c;
                        }
                    }
                }
            }
            else{
                if(s3.size()<n/2){
                    s3.insert({a[i].c,a[i].a,a[i].b});
                    ans+=a[i].c;
                }
                else{
                    auto tmp=*s3.begin();
                    if(tmp.cur+max(a[i].a,a[i].b)<a[i].c+max(tmp.a1,tmp.a2)){
                        if(tmp.a1>tmp.a2){
                            s3.erase(s3.find(tmp));
                            ans-=tmp.cur;
                            ans+=tmp.a1;
                            s1.insert({tmp.a1,tmp.a2,tmp.cur});
                            ans+=a[i].c;
                        }
                        else{
                            s3.erase(s3.find(tmp));
                            ans-=tmp.cur;
                            ans+=tmp.a2;
                            s2.insert({tmp.a2,tmp.a1,tmp.cur});
                            ans+=a[i].c;
                        }
                        s3.insert({a[i].c,a[i].a,a[i].b});
                    }
                    else{
                        if(a[i].a>a[i].b){
                            s1.insert({a[i].a,a[i].b,a[i].c});
                            ans+=a[i].a;
                        }
                        else{
                            s2.insert({a[i].b,a[i].a,a[i].c});
                            ans+=a[i].b;
                        }
                    }
                }
            }
            //cerr << ans << " ";
        }
        cout << ans << endl;
    }
    return 0;
}
