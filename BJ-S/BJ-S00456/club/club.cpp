#include<bits/stdc++.h>
using namespace std;
const int N=100005;

int t;

struct stu{
    int fstlv,fstnum;
    int scdlv,scdnum;
}st[N];

int fv1,fv2,fv3;

int n;
long long ans;

stu pai[N];
int cnt;

bool cmp(stu a,stu b){
    return (a.fstnum-a.scdnum) > (b.fstnum-b.scdnum);
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        fv1=fv2=fv3=0;
        ans=cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            int maxn=max(max(a,b),c);
            if(maxn==a){
                fv1++;
                st[i].fstlv=1;
                st[i].fstnum=a;
                if(b>c){
                    st[i].scdlv=2;
                    st[i].scdnum=b;
                }
                else{
                    st[i].scdlv=3;
                    st[i].scdnum=c;
                }
            }
            else if(maxn==b){
                fv2++;
                st[i].fstlv=2;
                st[i].fstnum=b;
                if(a>c){
                    st[i].scdlv=1;
                    st[i].scdnum=a;
                }
                else{
                    st[i].scdlv=3;
                    st[i].scdnum=c;
                }
            }
            else{
                fv3++;
                st[i].fstlv=3;
                st[i].fstnum=c;
                if(a>b){
                    st[i].scdlv=1;
                    st[i].scdnum=a;
                }
                else{
                    st[i].scdlv=2;
                    st[i].scdnum=b;
                }
            }
        }
        if(max(max(fv1,fv2),fv3)<=n/2){
            for(int i=1;i<=n;i++){
                ans=ans+st[i].fstnum;
            }
        }
        else{
            int she;
            if(fv1>n/2) she=1;
            else if(fv2>n/2) she=2;
            else she=3;
            for(int i=1;i<=n;i++){
                if(st[i].fstlv==she){
                    cnt++;
                    pai[cnt].fstlv=st[i].fstlv,pai[cnt].fstnum=st[i].fstnum,pai[cnt].scdlv=st[i].scdlv,pai[cnt].scdnum=st[i].scdnum;
                }
                else{
                    ans=ans+st[i].fstnum;
                }
            }
            sort(pai+1,pai+cnt+1,cmp);
            for(int i=1;i<=cnt;i++){
                if(i<=n/2){
                    ans=ans+pai[i].fstnum;
                }
                else{
                    ans=ans+pai[i].scdnum;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
