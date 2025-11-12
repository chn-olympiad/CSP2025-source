#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
pair<string,string> p[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s,c;
        cin>>s>>c;
        p[i].first=s;p[i].second=c;
    }
    while(q--){
        string t1,t2;
        cin>>t1>>t2;

        if(t1.size()!=t2.size()){
            cout<<0<<endl;
            continue;
        }
        int m=t1.size(),diff=0,sum=0;
        for(int i=0;i<t1.size();i++){
            if(t1[i]!=t2[i]) diff++;
        }
        for(int i=1;i<=n;i++){
            int st1=t1.find(p[i].first),st2=t2.find(p[i].second);
            int dick=0;
            for(int j=0;j<p[i].first.size();j++)
                if(p[i].first[j]!=p[i].second[j]) dick++;
            if(st1>=0 && st1<m && st2>=0 && st2<m){
                if(st1==st2 && diff==dick) sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
