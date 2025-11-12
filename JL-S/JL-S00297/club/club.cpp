#include<bits/stdc++.h>
using namespace std;
int read(){
    int n=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        n=(n<<3)+(n<<1)+(ch^48);
        ch=getchar();
    }
    return n*f;
}
const int N=1e5+5;
struct node{
    int s1,s2,s3;
    int k;
}a[N];
int pos1[N],pos2[N],pos3[N];
bool cmp(node x,node y){
    if(x.k!=y.k) return x.k>y.k;
    return max(x.s1,max(x.s2,x.s3))>max(x.s1,max(x.s2,x.s3));
}
bool cmp2(node x,node y){
    return max(x.s1,max(x.s2,x.s3))>max(x.s1,max(x.s2,x.s3));
}
bool cmp3(node x,node y){
    return x.s1>y.s1;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--){
        memset(a,0,sizeof(a));
        int n=read();
        int cnt1=0,cnt2=0,cnt3=0;
        int ct02=0,ct03=0;
        for(int i=1;i<=n;i++){
            a[i].s1=read();
            a[i].s2=read();
            a[i].s3=read();
            int s1=a[i].s1;
            int s2=a[i].s2;
            int s3=a[i].s3;
            if(s2!=0) ct02=1;
            if(s3!=0) ct03=1;
            a[i].k=max(s1,max(s2,s3))-min(s1,min(s2,s3));
        }
        long long ans=0,ans2=0;
        int flag=0;
        if(ct03==0&&ct02==0){
            sort(a+1,a+n+1,cmp3);
            for(int i=1;i<=n/2;i++){
                ans+=a[i].s1;
            }
            flag=1;
            cout<<ans<<endl;
            continue;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            int s1=a[i].s1;
            int s2=a[i].s2;
            int s3=a[i].s3;
            int maxn=max(s1,max(s2,s3));
            if(maxn==s1){
                if(cnt1!=n/2){
                    ans+=s1;
                    cnt1++;
                }else{
                    maxn=max(s2,s3);
                    if(cnt2==n/2){
                        ans+=s3;
                        cnt3++;
                    }else if(cnt3==n/2){
                        ans+=s2;
                        cnt2++;
                    }else if(maxn==s2){
                        ans+=s2;
                        cnt2++;
                    }else{
                        ans+=s3;
                        cnt3++;
                    }
                }
            }else if(maxn==s2){
                if(cnt2!=n/2){
                    ans+=s2;
                    cnt2++;
                }else{
                    maxn=max(s1,s3);
                    if(cnt1==n/2){
                        ans+=s3;
                        cnt3++;
                    }else if(cnt3==n/2){
                        ans+=s1;
                        cnt1++;
                    }else if(maxn==s1){
                        ans+=s1;
                        cnt1++;
                    }else{
                        ans+=s3;
                        cnt3++;
                    }
                }
            }else{
                if(cnt3!=n/2){
                    ans+=s3;
                    cnt3++;
                }else{
                    maxn=max(s1,s2);
                    if(cnt1==n/2){
                        ans+=s2;
                        cnt2++;
                    }else if(cnt2==n/2){
                        ans+=s1;
                        cnt1++;
                    }else if(maxn==s1){
                        ans+=s1;
                        cnt1++;
                    }else{
                        ans+=s2;
                        cnt2++;
                    }
                }
            }
        }
        cnt1=cnt2=cnt3=0;
        ans2=ans;
        ans=0;
        sort(a+1,a+n+1,cmp2);
           for(int i=1;i<=n;i++){
            int s1=a[i].s1;
            int s2=a[i].s2;
            int s3=a[i].s3;
            int maxn=max(s1,max(s2,s3));
            if(maxn==s1){
                if(cnt1!=n/2){
                    ans+=s1;
                    cnt1++;
                }else{
                    maxn=max(s2,s3);
                    if(cnt2==n/2){
                        ans+=s3;
                        cnt3++;
                    }else if(cnt3==n/2){
                        ans+=s2;
                        cnt2++;
                    }else if(maxn==s2){
                        ans+=s2;
                        cnt2++;
                    }else{
                        ans+=s3;
                        cnt3++;
                    }
                }
            }else if(maxn==s2){
                if(cnt2!=n/2){
                    ans+=s2;
                    cnt2++;
                }else{
                    maxn=max(s1,s3);
                    if(cnt1==n/2){
                        ans+=s3;
                        cnt3++;
                    }else if(cnt3==n/2){
                        ans+=s1;
                        cnt1++;
                    }else if(maxn==s1){
                        ans+=s1;
                        cnt1++;
                    }else{
                        ans+=s3;
                        cnt3++;
                    }
                }
            }else{
                if(cnt3!=n/2){
                    ans+=s3;
                    cnt3++;
                }else{
                    maxn=max(s1,s2);
                    if(cnt1==n/2){
                        ans+=s2;
                        cnt2++;
                    }else if(cnt2==n/2){
                        ans+=s1;
                        cnt1++;
                    }else if(maxn==s1){
                        ans+=s1;
                        cnt1++;
                    }else{
                        ans+=s2;
                        cnt2++;
                    }
                }
            }
        }
        if(!flag)cout<<max(ans,ans2)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
