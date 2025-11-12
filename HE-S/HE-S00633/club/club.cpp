#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100005
ll T,n,m,ans=0,top=1;
ll flag,a[maxn][4],cnt[4],op[maxn];
pair<ll,ll>k[maxn];
bool cmp(pair<ll,ll> A,pair<ll,ll> B){
    return A.second>B.second;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while (T--){
    	memset(op,0,sizeof(op));
		memset(cnt,0,sizeof(cnt));
		flag=0; 
        ans=0;
        top=1;
        cin>>n;
        m=n/2;
        for (int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            ll A=a[i][1],B=a[i][2],C=a[i][3];
            if (A>=B && A>=C) {
                cnt[1]++;
                op[i]=1;
            }else if (B>=A && B>=C){
                cnt[2]++;
                op[i]=2;
            }else  {
                cnt[3]++;
                op[i]=3;
            }
        }
        if (cnt[1]>=cnt[2] && cnt[1]>=cnt[3]){
            for (int i=1;i<=n;i++){
                if (op[i]!=1) ans+=max(a[i][2],a[i][3]);
                else {
                    k[top++]=pair<ll,ll>{i,a[i][1]-max(a[i][2],a[i][3])};
                }
            }
            sort(k+1,k+top+1,cmp);
            for (int i=1;i<top;i++){
                if (flag<m){
                    ans+=a[k[i].first][1];
                    flag++;
                }else ans+=max(a[k[i].first][2],a[k[i].first][3]);
            }
        }else if (cnt[2]>=cnt[1] && cnt[2]>=cnt[3]){
            for (int i=1;i<=n;i++){
                if (op[i]!=2) ans+=max(a[i][1],a[i][3]);
                else {
                    k[top++]=pair<ll,ll>{i,a[i][2]-max(a[i][1],a[i][3])};
                }
            }
            sort(k+1,k+top+1,cmp);
            for (int i=1;i<=top;i++){
                if (flag<m){
                    ans+=a[k[i].first][2];
                    flag++;
                }else ans+=max(a[k[i].first][1],a[k[i].first][3]);
            }
        }else {
            for (int i=1;i<=n;i++){
                if (op[i]!=3) ans+=max(a[i][2],a[i][1]);
                else {
                    k[top++]=pair<ll,ll>{i,a[i][3]-max(a[i][2],a[i][1])};
                }
            }
            sort(k+1,k+top+1,cmp);
            for (int i=1;i<=top;i++){
                if (flag<m){
                    ans+=a[k[i].first][3];
                    flag++;
                }else max(a[k[i].first][2],a[k[i].first][1]);
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//Ren5Jie4Di4Ling5%
