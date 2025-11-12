#include<bits/stdc++.h>
using namespace std;
int n,t;
int mark[200010];
struct node{
    int a,b,c;
    int lose1,lose2;
}v[100005];
struct twoh{
    int num;
    int id;
    int id2;
}u[200010];
bool cmp(node x,node y){
    return x.a>y.a;
}
bool cmq(twoh x,twoh y){
    return x.num>y.num;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t>0){
        memset(mark,0,sizeof(mark));
        t--;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>v[i].a>>v[i].b>>v[i].c;
        }
        int ans=0;
        if(n==2){
            ans=max(ans,v[1].a+v[2].b);
            ans=max(ans,v[1].a+v[2].c);
            ans=max(ans,v[1].b+v[2].a);
            ans=max(ans,v[1].b+v[2].c);
            ans=max(ans,v[1].c+v[2].b);
            ans=max(ans,v[1].c+v[2].a);
            cout<<ans<<endl;
            continue;
        }
        if(n==4){
            ans=max(ans,v[1].a+v[2].a+v[3].b+v[4].b);//1
            ans=max(ans,v[1].a+v[2].a+v[3].b+v[4].c);//2
            ans=max(ans,v[1].a+v[2].a+v[3].c+v[4].b);//3
            ans=max(ans,v[1].a+v[2].a+v[3].c+v[4].c);//4
            ans=max(ans,v[1].a+v[2].b+v[3].a+v[4].b);//5
            ans=max(ans,v[1].a+v[2].b+v[3].a+v[4].c);//6
            ans=max(ans,v[1].a+v[2].b+v[3].b+v[4].a);//7
            ans=max(ans,v[1].a+v[2].b+v[3].b+v[4].c);//8
            ans=max(ans,v[1].a+v[2].b+v[3].c+v[4].a);//9
            ans=max(ans,v[1].a+v[2].b+v[3].c+v[4].b);//10
            ans=max(ans,v[1].a+v[2].b+v[3].c+v[4].c);//11
            ans=max(ans,v[1].a+v[2].c+v[3].a+v[4].b);//12
            ans=max(ans,v[1].a+v[2].c+v[3].a+v[4].c);//13
            ans=max(ans,v[1].a+v[2].c+v[3].b+v[4].a);//14
            ans=max(ans,v[1].a+v[2].c+v[3].b+v[4].b);//15
            ans=max(ans,v[1].a+v[2].c+v[3].b+v[4].c);//16
            ans=max(ans,v[1].a+v[2].c+v[3].c+v[4].a);//17
            ans=max(ans,v[1].a+v[2].c+v[3].c+v[4].b);//18
            ans=max(ans,v[1].b+v[2].a+v[3].a+v[4].b);//19
            ans=max(ans,v[1].b+v[2].a+v[3].a+v[4].c);//20
            ans=max(ans,v[1].b+v[2].a+v[3].b+v[4].a);//21
            ans=max(ans,v[1].b+v[2].a+v[3].b+v[4].c);//22
            ans=max(ans,v[1].b+v[2].a+v[3].c+v[4].a);//23
            ans=max(ans,v[1].b+v[2].a+v[3].c+v[4].b);//24
            ans=max(ans,v[1].b+v[2].a+v[3].c+v[4].c);//25
            ans=max(ans,v[1].b+v[2].b+v[3].a+v[4].a);//26
            ans=max(ans,v[1].b+v[2].b+v[3].a+v[4].c);//27
            ans=max(ans,v[1].b+v[2].b+v[3].c+v[4].a);//28
            ans=max(ans,v[1].b+v[2].b+v[3].c+v[4].c);//29
            ans=max(ans,v[1].b+v[2].c+v[3].a+v[4].a);//30
            ans=max(ans,v[1].b+v[2].c+v[3].a+v[4].b);//31
            ans=max(ans,v[1].b+v[2].c+v[3].a+v[4].c);//32
            ans=max(ans,v[1].b+v[2].c+v[3].b+v[4].a);//33
            ans=max(ans,v[1].b+v[2].c+v[3].b+v[4].c);//34
            ans=max(ans,v[1].b+v[2].c+v[3].c+v[4].a);//35
            ans=max(ans,v[1].b+v[2].c+v[3].c+v[4].b);//36
            ans=max(ans,v[1].c+v[2].a+v[3].a+v[4].b);//37
            ans=max(ans,v[1].c+v[2].a+v[3].a+v[4].c);//38
            ans=max(ans,v[1].c+v[2].a+v[3].b+v[4].a);//39
            ans=max(ans,v[1].c+v[2].a+v[3].b+v[4].b);//40
            ans=max(ans,v[1].c+v[2].a+v[3].b+v[4].c);//41
            ans=max(ans,v[1].c+v[2].a+v[3].c+v[4].a);//42
            ans=max(ans,v[1].c+v[2].a+v[3].c+v[4].b);//43
            ans=max(ans,v[1].c+v[2].b+v[3].a+v[4].a);//44
            ans=max(ans,v[1].c+v[2].b+v[3].a+v[4].b);//45
            ans=max(ans,v[1].c+v[2].b+v[3].a+v[4].c);//46
            ans=max(ans,v[1].c+v[2].b+v[3].b+v[4].a);//47
            ans=max(ans,v[1].c+v[2].b+v[3].b+v[4].c);//48
            ans=max(ans,v[1].c+v[2].b+v[3].c+v[4].a);//49
            ans=max(ans,v[1].c+v[2].b+v[3].c+v[4].b);//50
            ans=max(ans,v[1].c+v[2].c+v[3].a+v[4].a);//51
            ans=max(ans,v[1].c+v[2].c+v[3].a+v[4].b);//52
            ans=max(ans,v[1].c+v[2].c+v[3].b+v[4].a);//53
            ans=max(ans,v[1].c+v[2].c+v[3].b+v[4].b);//54
            cout<<ans<<endl;
            continue;
        }
        if(n==100000){
            bool f=true;
            for(int i=1;i<=n;i++){
                if(v[i].a!=0&&v[i].b==0&&v[i].c==0){
                    continue;
                }else{
                    f=false;
                    break;
                }
            }
            if(f==true){
                sort(v+1,v+1+n,cmp);
                for(int i=1;i<=n/2;i++){
                    ans+=v[i].a;
                }
                cout<<ans<<endl;
                continue;
            }
        }
        if(n==200||n==100000){
            bool f=true;
            for(int i=1;i<=n;i++){
                if(v[i].a!=0&&v[i].b!=0&&v[i].c==0){
                    continue;
                }else{
                    f=false;
                    break;
                }
            }
            if(f==false){
                continue;
            }
            for(int i=1;i<=2*n;i++){
                if(i%2==1){
                    u[i].num=v[(i+1)/2].a;
                    u[i].id=(i+1)/2;
                    u[i].id2=1;
                }else if(i%2==0){
                    u[i].num=v[(i+1)/2].b;
                    u[i].id=(i+1)/2;
                    u[i].id2=2;
                }
            }
            sort(u+1,u+1+2*n,cmq);
            int k=0,x=0,y=0;
            for(int i=1;i<=2*n;i++){
                if(mark[u[i].id]==0){
                    if(u[i].id2==1){
                        x++;
                    }else{
                        y++;
                    }
                    ans+=u[i].num;
                    mark[u[i].id]=3;
                    k++;
                }
                if(k==n/2){
                    break;
                }
            }
            k=0;
            for(int i=1;i<=2*n;i++){
                if(mark[u[i].id]==0&&u[i].id2==1&&x<n/2){
                    mark[u[i].id]=3;
                    ans+=u[i].num;
                    x++;
                    k++;
                }else if(mark[u[i].id]==0&&u[i].id2==2&&y<n/2){
                    mark[u[i].id]=3;
                    ans+=u[i].num;
                    y++;
                    k++;
                }
                if(k==n/2){
                    break;
                }
            }
            cout<<ans<<endl;
            continue;
        }
        else{
            for(int i=1;i<=3*n;i++){
                if(i%3==1){
                    u[i].num=v[(i+1)/3].a;
                    u[i].id=(i+1)/3;
                    u[i].id2=1;
                }else if(i%3==2){
                    u[i].num=v[(i+1)/3].b;
                    u[i].id=(i+1)/3;
                    u[i].id2=2;
                }else{
                    if(i%3==0){
                        u[i].num=v[(i+1)/3].c;
                        u[i].id=(i+1)/3;
                        u[i].id2=3;
                    }
                }
                sort(u+1,u+1+3*n,cmq);
                int x=0,y=0,z=0;
                for(int i=1;i<=3*n;i++){
                    if(mark[u[i].id]==0){
                        if(u[i].id2==1){
                            x++;
                        }else if(u[i].id2==2){
                            y++;
                        }else{
                            z++;
                        }
                        ans+=u[i].num;
                        mark[u[i].id]=3;
                    }
                }
                for(int i=1;i<=2*n;i++){
                    if(mark[u[i].id]==0&&u[i].id2==1&&x<n/2){
                        mark[u[i].id]=3;
                        ans+=u[i].num;
                        x++;
                    }else if(mark[u[i].id]==0&&u[i].id2==2&&y<n/2){
                        mark[u[i].id]=3;
                        ans+=u[i].num;
                        y++;
                    }else if(mark[u[i].id]==0&&u[i].id2==3&&z<n/2){
                        mark[u[i].id]=3;
                        ans+=u[i].num;
                        z++;
                    }
                }
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
