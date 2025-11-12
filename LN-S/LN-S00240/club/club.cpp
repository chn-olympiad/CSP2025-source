#include<bits/stdc++.h>
using namespace std;
int t,n,sum[100005],bul[20005];
struct node{
    int id,a,b,c,mx;
}ps[100005];
bool cmp(node x,node y){
    return x.mx>y.mx;
}
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(sum,0,sizeof(sum));
        memset(bul,0,sizeof(bul));
        memset(ps,0,sizeof(ps));
        cin>>n;
        int u = n/2,flag = 0;
        for(int i = 1;i<=n;i++){
            cin>>ps[i].a>>ps[i].b>>ps[i].c;
            ps[i].id = i;
            ps[i].mx = max(ps[i].a,max(ps[i].b,ps[i].c));
            if(bul[ps[i].a] == 0){
                sum[++flag] = ps[i].a;
                bul[ps[i].a]++;
            }
            if(bul[ps[i].b] == 0){
                sum[++flag] = ps[i].b;
                bul[ps[i].b]++;
            }
            if(bul[ps[i].c] == 0){
                sum[++flag] = ps[i].c;
                bul[ps[i].c]++;
            }
        }
        sort(sum+1,sum+flag+1);
        sort(ps+1,ps+n+1,cmp);
        int cnt1 = 0,cnt2 = 0,cnt3 = 0,ans = 0;
        for(int i = 1;i<=n;i++){
            if(ps[i].a>ps[i].b&&ps[i].a>ps[i].c){
                cnt1++;
                ans+=ps[i].a;
            }
            if(ps[i].b>ps[i].a&&ps[i].b>ps[i].c){
                cnt2++;
                ans+=ps[i].b;
            }
            if(ps[i].c>ps[i].a&&ps[i].c>ps[i].b){
                cnt3++;
                ans+=ps[i].c;
            }
        }
        if(cnt1<=u&&cnt2<=u&&cnt3<=u){
            cout<<ans<<endl;
            continue;
        }
        else{
            if(cnt1>u){
                int s1 = 0,s2 = 0;
                int f = cnt1-u;
                int x = cnt1;
                int xx = cnt2;
                int xxx = cnt3;
                for(int i = n;i>=n-f+1;i--){
                    for(int j = flag;j>=1;j--){
                        if(cnt1 == u) break;
                        if(ps[i].b == sum[j]&&cnt2<u){
                            s1+=(ps[i].a-ps[i].b);
                            cnt2++;
                            cnt1--;
                        }
                        if(ps[i].c == sum[j]&&cnt3<u){
                            s1+=(ps[i].a-ps[i].c);
                            cnt3++;
                            cnt1--;
                        }
                    }
                }
                cnt1 = x,cnt2 = xx,cnt3 = xxx;
                for(int i = 1;i<=f;i++){
                    for(int j = flag;j>=1;j--){
                        if(cnt1 == u) break;
                        if(ps[i].b == sum[j]&&cnt2<u){
                            s2+=(ps[i].a-ps[i].b);
                            cnt2++;
                            cnt1--;
                        }
                        if(ps[i].c == sum[j]&&cnt3<u){
                            s2+=(ps[i].a-ps[i].c);
                            cnt3++;
                            cnt1--;
                        }
                    }
                }
                ans-=min(s1,s2);
            }
            else if(cnt2>u){
                int s1 = 0,s2 = 0;
                int f = cnt2-u;
                int x = cnt1;
                int xx = cnt2;
                int xxx = cnt3;
                for(int i = n;i>=n-f+1;i--){
                    for(int j = flag;j>=1;j--){
                        if(cnt2 == u) break;
                        if(ps[i].a == sum[j]&&cnt1<u){
                            s1+=(ps[i].b-ps[i].a);
                            cnt1++;
                            cnt2--;
                        }
                        if(ps[i].c == sum[j]&&cnt3<u){
                            s1+=(ps[i].b-ps[i].c);
                            cnt3++;
                            cnt2--;
                        }
                    }
                }
                cnt1 = x,cnt2 = xx,cnt3 = xxx;
                for(int i = 1;i<=f;i++){
                    for(int j = flag;j>=1;j--){
                        if(cnt2 == u) break;
                        if(ps[i].a == sum[j]&&cnt1<u){
                            s2+=(ps[i].b-ps[i].a);
                            cnt1++;
                            cnt2--;
                        }
                        if(ps[i].c == sum[j]&&cnt3<u){
                            s2+=(ps[i].b-ps[i].c);
                            cnt3++;
                            cnt2--;
                        }
                    }
                }
                ans-=min(s1,s2);
            }
            else if(cnt3>u){
                int s1 = 0,s2 = 0;
                int f = cnt3-u;
                int x = cnt1;
                int xx = cnt2;
                int xxx = cnt3;
                for(int i = n;i>=n-f+1;i--){
                    for(int j = flag;j>=1;j--){
                        if(cnt3 == u) break;
                        if(ps[i].a == sum[j]&&cnt1<u){
                            s1+=(ps[i].c-ps[i].a);
                            cnt1++;
                            cnt3--;
                        }
                        if(ps[i].b == sum[j]&&cnt2<u){
                            s1+=(ps[i].c-ps[i].b);
                            cnt2++;
                            cnt3--;
                        }
                    }
                }
                cnt1 = x,cnt2 = xx,cnt3 = xxx;
                for(int i = 1;i<=f;i++){
                    for(int j = flag;j>=1;j--){
                        if(cnt3 == u) break;
                        if(ps[i].a == sum[j]&&cnt1<u){
                            s2+=(ps[i].c-ps[i].a);
                            cnt1++;
                            cnt3--;
                        }
                        if(ps[i].b == sum[j]&&cnt2<u){
                            s2+=(ps[i].c-ps[i].b);
                            cnt2++;
                            cnt3--;
                        }
                    }
                }
                ans-=min(s1,s2);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
