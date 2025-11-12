#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string>m;
unordered_map<string,string>::iterator it;
int n,q,qs1,qs2,cnt;
string s1,s2,q1,q2,c1,x,y,z;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        m[s1]=s2;
    }

    for(int i=1;i<=q;i++){
        cin>>s1>>s2;
        cnt=0;
        for(it=m.begin();it!=m.end();it++){
            c1=s1;
            q1=it->first;
            q2=it->second;
            qs1=s1.find(q1,0);
            qs2=s2.find(q2,0);
            if(qs1==-1){
                continue;
            }
            if(qs1==qs2){
                q1=s1.substr(qs1+q1.size(),qs1-(qs1+q1.size()));
                q2=s2.substr(qs2+q2.size(),qs2-(qs2+q2.size()));
                if(q1==q2){
                    cnt++;
                    continue;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
