#include<bits/stdc++.h>
using namespace std;

struct node{
    long long a,b,c,s1;
    char max1;
};
node s[10010];
long long ans,ansa,ansb,ansc;
bool cmp(node a1,node a2){
    return a1.s1<a2.s1;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    for(long long i=0;i<t;i++){
            ans=0,ansa=0,ansb=0,ansc=0;
        long long n;
        cin>>n;
        for(long long j=0;j<n;j++){
            cin>>s[j].a>>s[j].b>>s[j].c;
            if(s[j].a>s[j].b&&s[j].a>s[j].c){
                s[j].max1='a';
                s[j].s1=s[j].a-max(s[j].b,s[j].c);
                ans+=s[j].a;
                ansa++;
            }
            else if(s[j].b>s[j].a&&s[j].b>s[j].c){
                s[j].max1='b';
                s[j].s1=s[j].b-max(s[j].a,s[j].c);
                ans+=s[j].b;
                ansb++;
            }
            else if(s[j].c>s[j].b&&s[j].c>s[j].a){
                s[j].max1='c';
                s[j].s1=s[j].c-max(s[j].b,s[j].a);
                ans+=s[j].c;
                ansc++;
            }
            //cout<<s[j].s1<<" ";
        }
        //cout<<s[0].s1;
        if(ansa>n/2){
               // cout<<1<<endl;
            sort(s,s+n,cmp);
            for(long long j=0;j<n;j++){
                    //cout<<s[j].s1;
                if(s[j].max1=='a'){
                    ansa--;
                    ans-=s[j].s1;
                }
                if(ansa==n/2) break;
            }
        }
         else if(ansb>n/2){
          //   cout<<2<<endl;
            sort(s,s+n,cmp);
            for(long long j=0;j<n;j++){
                    //cout<<s[j].s1;
                if(s[j].max1=='b'){
                    ansb--;
                    ans-=s[j].s1;
                }
                if(ansb==n/2) break;
            }
        }
        else if(ansc>n/2){
            //cout<<3<<endl;
            sort(s,s+n,cmp);
            for(long long j=0;j<n;j++){
                    //cout<<s[j].s1;
                if(s[j].max1=='c'){
                    ansc--;
                    ans-=s[j].s1;
                }
                if(ansc==n/2) break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
