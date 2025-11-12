#include<bits/stdc++.h>
using namespace std;
struct like{
    int id,v;
    void input(int i){
        id=i;scanf("%d",&v);
    }
}l1[100005],l2[100005],l3[100005];
int T,n,a0,a1,a2,a3,a4,a5,cnt1,cnt2,cnt3;bool f[100005];
bool cmp(like x,like y){
    return x.v>y.v;
}
int dfs(int id,int p){
    if(id>n)return 0;int a1=0,a2=0,a3=0,a;
    if(cnt1<n/2){
        cnt1++;a1=dfs(id+1,1);cnt1--;
    }if(cnt2<n/2){
        cnt2++;a2=dfs(id+1,2);cnt2--;
    }if(cnt3<n/2){
        cnt3++;a3=dfs(id+1,3);cnt3--;
    }switch(p){
        case 0:a=0;break;
        case 1:a=l1[id].v;break;
        case 2:a=l2[id].v;break;
        case 3:a=l3[id].v;break;
    }
    return a+max(a1,max(a2,a3));
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);a0=a1=a2=a3=a4=a5;
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){l1[i].input(i);l2[i].input(i);l3[i].input(i);}
        if(n<=10){
            printf("%d\n",dfs(0,0));continue;
        }
        sort(l1+1,l1+n+1,cmp);sort(l2+1,l2+n+1,cmp);sort(l3+1,l3+n+1,cmp);
        cnt1=cnt2=cnt3=0;
        for(int i=1;i<=n;i++){
             if(!f[l1[i].id]&&cnt1<n/2){
                a0+=l1[i].v;f[l1[i].id]=1;cnt1++;
            }if(!f[l2[i].id]&&cnt2<n/2){
                a0+=l2[i].v;f[l2[i].id]=1;cnt2++;
            }if(!f[l3[i].id]&&cnt3<n/2){
                a0+=l3[i].v;f[l3[i].id]=1;cnt3++;
            }
        }
        cnt1=cnt2=cnt3=0;
        for(int i=1;i<=n;i++){
             if(!f[l1[i].id]&&cnt1<n/2){
                a1+=l1[i].v;f[l1[i].id]=1;cnt1++;
            }if(!f[l3[i].id]&&cnt3<n/2){
                a1+=l3[i].v;f[l3[i].id]=1;cnt3++;
            }if(!f[l2[i].id]&&cnt2<n/2){
                a1+=l2[i].v;f[l2[i].id]=1;cnt2++;
            }
        }
        cnt1=cnt2=cnt3=0;
        for(int i=1;i<=n;i++){
             if(!f[l2[i].id]&&cnt2<n/2){
                a2+=l2[i].v;f[l2[i].id]=1;cnt2++;
            }if(!f[l1[i].id]&&cnt1<n/2){
                a2+=l1[i].v;f[l1[i].id]=1;cnt1++;
            }if(!f[l3[i].id]&&cnt3<n/2){
                a2+=l3[i].v;f[l3[i].id]=1;cnt3++;
            }
        }
        cnt1=cnt2=cnt3=0;
        for(int i=1;i<=n;i++){
             if(!f[l2[i].id]&&cnt2<n/2){
                a3+=l2[i].v;f[l2[i].id]=1;cnt2++;
            }if(!f[l3[i].id]&&cnt3<n/2){
                a3+=l3[i].v;f[l3[i].id]=1;cnt3++;
            }if(!f[l1[i].id]&&cnt1<n/2){
                a3+=l1[i].v;f[l1[i].id]=1;cnt1++;
            }
        }
        cnt1=cnt2=cnt3=0;
        for(int i=1;i<=n;i++){
             if(!f[l3[i].id]&&cnt3<n/2){
                a4+=l3[i].v;f[l3[i].id]=1;cnt3++;
            }if(!f[l1[i].id]&&cnt1<n/2){
                a4+=l1[i].v;f[l1[i].id]=1;cnt1++;
            }if(!f[l2[i].id]&&cnt2<n/2){
                a4+=l2[i].v;f[l2[i].id]=1;cnt2++;
            }
        }
        cnt1=cnt2=cnt3=0;
        for(int i=1;i<=n;i++){
             if(!f[l3[i].id]&&cnt3<n/2){
                a5+=l3[i].v;f[l3[i].id]=1;cnt3++;
            }if(!f[l2[i].id]&&cnt2<n/2){
                a5+=l2[i].v;f[l2[i].id]=1;cnt2++;
            }if(!f[l1[i].id]&&cnt1<n/2){
                a5+=l1[i].v;f[l1[i].id]=1;cnt1++;
            }
        }printf("%d\n",max(max(a0,max(a1,a2)),max(a3,max(a4,a5))));
    }
    return 0;
}
