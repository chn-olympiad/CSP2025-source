#include<bits/stdc++.h>
using namespace std;
struct l{
    int a,b,c;
}a[100005];
int p1[100005],p2[100005],p3[100005];
bool cmp1(int x,int y){
    return min(a[x].a-a[x].b,a[x].a-a[x].c)<min(a[y].a-a[y].b,a[y].a-a[y].c);
}
bool cmp2(int x,int y){
    return min(a[x].b-a[x].a,a[x].b-a[x].c)<min(a[y].b-a[y].a,a[y].b-a[y].c);
}
bool cmp3(int x,int y){
    return min(a[x].c-a[x].a,a[x].c-a[x].b)<min(a[y].c-a[y].a,a[y].c-a[y].b);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(a,0,sizeof a);
        memset(p1,0,sizeof p1);
        memset(p2,0,sizeof p3);
        memset(p3,0,sizeof p3);
        long long a1=0;
        long long q1=0,q2=0,q3=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            if(a[i].a>=a[i].b && a[i].a>=a[i].c){
                p1[++q1]=i;
                a1+=a[i].a;
            }
            else if(a[i].b>=a[i].a && a[i].b>=a[i].c){
                p2[++q2]=i;
                a1+=a[i].b;
            }
            else{
                p3[++q3]=i;
                a1+=a[i].c;
            }
        }
        if(q1>n/2){
            sort(p1+1,p1+q1+1,cmp1);
            for(int i=1;i<=q1-n/2;i++){
                a1-=a[p1[i]].a;
                if(a[p1[i]].b>a[p1[i]].c){
                    q2++;
                    a1+=a[p1[i]].b;
                }
                else{
                    q3++;
                    a1+=a[p1[i]].c;
                }
            }
            q1=n/2;
        }
        else if(q2>n/2){
            sort(p2+1,p2+q2+1,cmp2);
            for(int i=1;i<=q2-n/2;i++){
                a1-=a[p2[i]].b;
                if(a[p2[i]].a>a[p2[i]].c){
                    q1++;
                    a1+=a[p2[i]].a;
                }
                else{
                    q3++;
                    a1+=a[p2[i]].c;
                }
            }
            q2=n/2;
        }
        else if(q3>n/2){
            sort(p3+1,p3+q3+1,cmp3);
            for(int i=1;i<=q3-n/2;i++){
                a1-=a[p3[i]].c;
                if(a[p3[i]].a>a[p3[i]].b){
                    q1++;
                    a1+=a[p3[i]].a;
                }
                else {
                    a1+=a[p3[i]].b;
                    q2++;
                }
            }
        }
        cout<<a1<<endl;
    }
    return 0;
}
