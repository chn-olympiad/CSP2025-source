#include<bits/stdc++.h>
using namespace std;
struct p{int num;int a;int b; int c;}r[100001];
bool cmp1(p n1,p n2){
    if(min(n1.a-n1.b,n1.a-n1.c)==min(n2.a-n2.b,n2.a-n2.c))return(n1.a<=n2.a);
    return(min(n1.a-n1.b,n1.a-n1.c)<=min(n2.a-n2.b,n2.a-n2.c));
}
bool cmp2(p n1,p n2){
    if(min(n1.b-n1.a,n1.b-n1.c)==min(n2.b-n2.c,n2.b-n2.a))return(n1.b<=n2.b);
    return(min(n1.b-n1.a,n1.b-n1.c)<=min(n2.b-n2.c,n2.b-n2.a));
}
bool cmp3(p n1,p n2){
    if(min(n1.c-n1.b,n1.c-n1.a)==min(n2.c-n2.b,n2.c-n2.a))return(n1.c<=n2.c);
    return(min(n1.c-n1.b,n1.c-n1.a)<=min(n2.c-n2.b,n2.c-n2.a));
}
int x,y,z;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    for(int tt=1;tt<=t;tt++){
        x=0;y=0;z=0;
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>r[i].a>>r[i].b>>r[i].c;
            if(r[i].a>=r[i].b&&r[i].a>=r[i].c){
                x++;r[i].num=1;
            }else if(r[i].b>=r[i].c&&r[i].b>=r[i].a){
                y++;r[i].num=2;
            }else{
                z++;r[i].num=3;
            }
        }
        if(x>n/2){
            sort(r+1,r+n+1,cmp1);int i=1;
            while(x>n/2){
                if(r[i].num==1){
                    x--;
                    if(r[i].a-r[i].b<r[i].a-r[i].c&&y<n/2){y++;r[i].num=2;}
                    if(r[i].a-r[i].c<r[i].a-r[i].b&&z<n/2){z++;r[i].num=3;}
                    if(r[i].a-r[i].b==r[i].a-r[i].c){if(y>z){z++;r[i].num=3;}else{y++;r[i].num=2;}}
                }
                i++;
            }
        }
        if(y>n/2){
            sort(r+1,r+n+1,cmp2);int i=1;
            while(y>n/2){
                if(r[i].num==2){
                    y--;
                    if(r[i].b-r[i].a<r[i].b-r[i].c&&x<n/2){x++;r[i].num=1;}
                    if(r[i].b-r[i].c<r[i].b-r[i].a&&z<n/2){z++;r[i].num=3;}
                    if(r[i].b-r[i].a==r[i].b-r[i].c){if(x>z){z++;r[i].num=3;}else{x++;r[i].num=1;}}
                }
                i++;
            }
        }
        if(z>n/2){
            sort(r+1,r+n+1,cmp3);int i=1;
            while(z>n/2){
                if(r[i].num==3){
                    z--;
                    if(r[i].c-r[i].b<r[i].c-r[i].a&&y<n/2){y++;r[i].num=2;}
                    if(r[i].c-r[i].a<r[i].c-r[i].b&&x<n/2){x++;r[i].num=1;}
                    if(r[i].c-r[i].b==r[i].c-r[i].a){if(y>x){x++;r[i].num=1;}else{y++;r[i].num=2;}}
                }
                i++;
            }
        }
        long long sum=0;
        for(int i=1;i<=n;i++){
            if(r[i].num==1)sum+=r[i].a;
            if(r[i].num==2)sum+=r[i].b;
            if(r[i].num==3)sum+=r[i].c;
        }
        cout<<sum<<endl;
    }
    return 0;
}
