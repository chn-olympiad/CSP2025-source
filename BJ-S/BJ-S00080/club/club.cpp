#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline int read(){
    int x=0;
    char c=getchar();
    while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
    return x;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t=read();
    while(t--){
        long long n=read(),ans=0;
        vector<int> a,b,c;
        vector<int> ta,tb,tc;
        int t1,t2,t3;
        for(int i=0;i<n;i++){
            t1=read();
            t2=read();
            t3=read();
            if(t1>t2&&t1>t3){
                a.push_back(t1);
                ans+=t1;
                ta.push_back(t1-max(t2,t3));
            }
            if(t2>t1&&t2>t3){
                b.push_back(t2);
                ans+=t2;
                tb.push_back(t2-max(t1,t3));
            }
            if(t3>t1&&t3>t2){
                c.push_back(t3);
                ans+=t3;
                tc.push_back(t2-max(t1,t2));
            }
        }
        if(a.size()>n/2){
            sort(ta.begin(),ta.end());
            int te=a.size()-(n/2);
            for(int i=0;i<te;i++)ans-=ta[i];
        }
        if(b.size()>n/2){
            sort(tb.begin(),tb.end());
            int te=b.size()-(n/2);
            for(int i=0;i<te;i++)ans-=tb[i];
        }
        if(c.size()>n/2){
            sort(tc.begin(),tc.end());
            int te=c.size()-(n/2);
            for(int i=0;i<te;i++)ans-=tc[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
