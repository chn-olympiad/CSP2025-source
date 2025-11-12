#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct stu{
    int a,b,c,b_a,a_b,c_a,a_c,c_b,b_c,maxn;
}s[N];
int t;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    memset(s,0,sizeof(s));
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
            s[i].b_a=s[i].b-s[i].a;
            s[i].a_b=s[i].a-s[i].b;
            s[i].c_a=s[i].c-s[i].a;
            s[i].a_c=s[i].a-s[i].c;
            s[i].c_b=s[i].c-s[i].b;
            s[i].b_c=s[i].b-s[i].c;
        }
        int cnt_a=0,cnt_b=0,cnt_c=0;
        long long num=0;
        int ta[N];
        int tb[N];
        int tc[N];
        for(int i=1;i<=n;i++){
            if(s[i].a==max(s[i].a,max(s[i].b,s[i].c))){
                cnt_a++;
                num+=s[i].a;
                ta[cnt_a]=min(s[i].a_b,s[i].a_b);
            }
            else if(s[i].b==max(s[i].a,max(s[i].b,s[i].c))){
                cnt_b++;
                num+=s[i].b;
                tb[cnt_b]=min(s[i].b_a,s[i].b_c);
            }
            else if(s[i].c==max(s[i].a,max(s[i].b,s[i].c))){
                cnt_c++;
                num+=s[i].c;
                tc[cnt_c]=min(s[i].c_b,s[i].c_a);
            }
        }
        if(cnt_a>(n/2)){
            sort(ta+1,ta+cnt_a+1);
            int need=cnt_a-(n/2);
            int cnt=0;
            for(int i=1;i<=need;i++){
                num-=ta[i];
            }
        }
        if(cnt_b>(n/2)){
            sort(tb+1,tb+cnt_b+1);
            int need=cnt_b-(n/2);
            int cnt=0;
            for(int i=1;i<=need;i++){
                num-=tb[i];
            }
        }
        if(cnt_c>(n/2)){
            sort(tc+1,tc+cnt_c+1);
            int need=cnt_c-(n/2);
            int cnt=0;
            for(int i=1;i<=need;i++){
                num-=tc[i];
            }
        }
        cout<<num<<endl;
    }
    return 0;
}
