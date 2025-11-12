#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
void write(long long x){
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t=read();
    while(t--){
        int n=read();
        vector<int> d[3];
        long long ans=0,cnt[3]={};
        for(int i=0;i<n;i++){
            int a=read(),b=read(),c=read();
            if(a>=b&&a>=c)cnt[0]++,d[0].push_back(a-max(b,c)),ans+=a;
            else if(b>=a&&b>=c)cnt[1]++,d[1].push_back(b-max(a,c)),ans+=b;
            else cnt[2]++,d[2].push_back(c-max(a,b)),ans+=c;
        }
        for(int i=0;i<3;i++)sort(d[i].begin(),d[i].end());
        for(int j=0;j<3;j++)
            for(int i=n/2;i<cnt[j];i++)ans-=d[j][i-n/2];
        write(ans),putchar('\n');
    }
    return 0;
}
//key:Ren5Jie4Di4Ling5%
