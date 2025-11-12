#include<bits/stdc++.h>
#define N 100005
using namespace std;
int t;
int n;
long long a[N],b[N],c[N];
int s[N];
long long res;
priority_queue<long long>pq;
int cnta,cntb,cntc;
void work(){
    scanf("%d",&n);
    res=cnta=cntb=cntc=0;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",a+i,b+i,c+i);
        if(a[i]>=b[i]&&a[i]>=c[i]){
            cnta++;
            res+=a[i];
            s[i]=1;
        }
        if(b[i]>a[i]&&b[i]>=c[i]){
            cntb++;
            res+=b[i];
            s[i]=2;
        }
        if(c[i]>a[i]&&c[i]>b[i]){
            cntc++;
            res+=c[i];
            s[i]=3;
        }
    }
    if(cntb>cnta){
        swap(cntb,cnta);
        for(int i=1;i<=n;i++){
            swap(a[i],b[i]);
            if(s[i]==2)s[i]=1;
            else if(s[i]==1)s[i]=2;
        }
    }
    if(cntc>cnta){
        swap(cntc,cnta);
        for(int i=1;i<=n;i++){
            swap(a[i],c[i]);
            if(s[i]==3)s[i]=1;
            else if(s[i]==1)s[i]=3;
        }
    }
    if(cnta>n/2){
        while(!pq.empty())pq.pop();
        for(int i=1;i<=n;i++){
            if(s[i]==1){
                pq.push(-(a[i]-max(b[i],c[i])));
            }
        }
        while(cnta>n/2){
            res+=pq.top();
            pq.pop();
            cnta--;
        }
    }
    printf("%lld\n",res);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        work();
    }
}