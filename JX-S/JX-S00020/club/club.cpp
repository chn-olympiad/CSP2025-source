#include <bits/stdc++.h>
using namespace std;
long long sum;
int t,n,a[9],ans1=20028,ans2,w;
struct kkk{
    int a,b,c,d;
}q[100028];
bool cmp1(kkk a,kkk b){
    return a.a>b.a;
}
bool cmp2(kkk a,kkk b){
    return a.b>b.b;
}
bool cmp3(kkk a,kkk b){
    return a.c>b.c;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;int k=1;
        sum=0;a[1]=0;a[2]=0;a[3]=0;
        for(int j=1;j<=n;j++){
            cin>>q[j].a>>q[j].b>>q[j].c;
            if(q[j].a>q[j].b&&q[j].a>q[j].c)q[j].d=1;
            if(q[j].b>q[j].a&&q[j].b>q[j].c)q[j].d=2;
            if(q[j].c>q[j].b&&q[j].c>q[j].a)q[j].d=3;
            if(q[j].b>0||q[j].c>0)k=0;
        }
        for(int j=1;j<=n;j++){
            a[q[j].d]++;ans2=0;w=0;ans1=0;
            if(a[q[j].d]>n/2){
                if(q[j].d==1){
                    for(int l=1;l<j;l++){
                        if(q[l].d==1){
                            if(q[j].a+max(q[l].b,q[l].c)>max(q[j].b,q[j].c)+q[l].a){
                                if(ans2<(q[j].a+max(q[l].b,q[l].c))-(max(q[j].b,q[j].c)+q[l].a)){
                                    ans1=l;w=1;
                                    ans2=(q[j].a+max(q[l].b,q[l].c))-(max(q[j].b,q[j].c)+q[l].a);
                                }
                            }
                        }
                    }
                    if(w){
                        sum-=q[ans1].a;
                        sum+=max(q[ans1].b,q[ans1].c);
                        if(q[ans1].b>q[ans1].c){
                            a[1]--;a[2]++;
                            q[ans1].d=2;
                        }else{
                            a[1]--;a[3]++;
                            q[ans1].d=3;
                        }
                    }
                    else{
                        if(q[j].b>q[j].c){
                            sum+=q[j].b;a[1]--;a[2]++;
                            q[j].d=2;
                        }else{
                            sum+=q[j].c;a[1]--;a[3]++;
                            q[j].d=3;
                        }
                        continue;
                    }
                }
                if(q[j].d==2){
                    for(int l=1;l<j;l++){
                        if(q[l].d==2){
                            if(q[j].b+max(q[l].a,q[l].c)>max(q[j].a,q[j].c)+q[l].b){
                                if(ans2<(q[j].b+max(q[l].a,q[l].c))-(max(q[j].a,q[j].c)+q[l].b)){
                                    ans1=l;w=1;
                                    ans2=(q[j].b+max(q[l].a,q[l].c))-(max(q[j].a,q[j].c)+q[l].b);
                                }

                            }
                        }
                    }
                    if(w){
                        sum+=max(q[ans1].a,q[ans1].c);
                        sum-=q[ans1].b;
                        if(q[ans1].a>q[ans1].c){
                            a[2]--;a[1]++;
                            q[ans1].d=1;
                        }else{
                            a[2]--;a[3]++;
                            q[ans1].d=3;
                        }
                    }
                    else{
                        if(q[j].a>q[j].c){
                            sum+=q[j].a;a[2]--;a[1]++;
                            q[j].d=1;
                        }else{
                            sum+=q[j].c;a[2]--;a[3]++;
                            q[j].d=3;
                        }
                        continue;
                    }
                }
                if(q[j].d==3){
                    for(int l=1;l<j;l++){
                        if(q[l].d==3){
                            if(q[j].c+max(q[l].b,q[l].a)>max(q[j].b,q[j].a)+q[l].c){
                                if(ans2<(q[j].c+max(q[l].b,q[l].a))-(max(q[j].b,q[j].a)+q[l].c)){
                                    ans1=l;w=1;
                                    ans2=(q[j].c+max(q[l].b,q[l].a))-(max(q[j].b,q[j].a)+q[l].c);
                                }
                            }
                        }
                    }
                    if(w){
                        sum+=max(q[ans1].b,q[ans1].a);
                        sum-=q[ans1].c;
                        if(q[ans1].b>q[ans1].a){
                            a[3]--;a[2]++;
                            q[ans1].d=2;
                        }else{
                            a[3]--;a[1]++;
                            q[ans1].d=1;
                        }
                    }
                    else{
                        if(q[j].a>q[j].b){
                            sum+=q[j].a;a[3]--;a[1]++;
                            q[j].d=1;
                        }else{
                            sum+=q[j].b;a[3]--;a[2]++;
                            q[j].d=2;
                        }
                        continue;
                    }
                }
            }
            if(q[j].d==1)sum+=q[j].a;
            else if(q[j].d==2)sum+=q[j].b;
            else sum+=q[j].c;
        }
        if(k){
            sum=0;
            for(int l=1;l<=n/2;l++){
                sum+=q[l].a;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
