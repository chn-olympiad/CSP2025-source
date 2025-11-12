#include<bits/stdc++.h>
using namespace std;
struct pl{
    int a,b,c;
    int maxx,cha;
}number[100005];
int aa,bb,cc;//0
bool pd(int i,int n){
    int d,x;
    int a1=number[i].a,b1=number[i].b,c1=number[i].c;
    if(number[i].maxx==a1){
        if(b1==-1&&c1==-1)return 0;
        if(c1==-1&&bb+1>n/2)return 0;
        if(b1==-1&&cc+1>n/2)return 0;
        d=max(b1,c1);x=min(b1,c1);
    }else if(number[i].maxx==b1){
        if(a1==-1&&c1==-1)return 0;
        if(a1==-1&&cc+1>n/2)return 0;
        if(c1==-1&&aa+1>n/2)return 0;
    }else{
        if(b1==-1&&a1==-1)return 0;
        if(a1==-1&&bb+1>n/2)return 0;
        if(b1==-1&&aa+1>n/2)return 0;
    }return 1;
}
void chuli(int i){
    int a1=number[i].a,b1=number[i].b,c1=number[i].c;
    if(number[i].maxx==a1){number[i].a=-1;
        number[i].maxx=max(b1,c1);
        number[i].cha=abs(b1-c1);
    }else if(number[i].maxx==b1){number[i].b=-1;
        number[i].maxx=max(a1,c1);
        number[i].cha=abs(a1-c1);
    }else{number[i].c=-1;
        number[i].maxx=max(b1,a1);
        number[i].cha=abs(b1-a1);
    }
    return;
}
bool cmp(pl x,pl y){
    return x.a>y.a;
}
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--){aa=0,bb=0,cc=0;
        int sum=0;
        int n;cin>>n;
        bool pd2=1;
        for(int i=1;i<=n;++i){
            cin>>number[i].a>>number[i].b>>number[i].c;
            int a1=number[i].a,b1=number[i].b,c1=number[i].c;
            if(c1!=0||b1!=0)pd2=0;
            if(a1>=b1&&a1>=c1){
                aa++;number[i].maxx=a1;number[i].cha=a1-max(b1,c1);
            }else if(b1>=c1&&b1>=a1){
                bb++;number[i].maxx=b1;number[i].cha=b1-max(a1,c1);
            }else{
                cc++;number[i].maxx=c1;number[i].cha=c1-max(a1,b1);
            }
            sum+=number[i].maxx;
        }
        if(pd2==1){sum=0;
            sort(number+1,number+n+1,cmp);
            for(int i=1;i<=n/2;++i){
                sum+=number[i].a;
            }cout<<sum<<endl;
            continue;
        }
        int minn=1000005,x;
        while(aa>n/2){
            for(int i=1;i<=n;++i){
                if(number[i].cha<=minn&&number[i].maxx!=0&&number[i].a!=-1&&pd(i,n)){
                    x=i;minn=number[i].cha;
                }
            }
            sum-=number[x].cha;
            aa--;
            chuli(x);
        }minn=1000005;
        while(bb>n/2){
            for(int i=1;i<=n;++i){
                if(number[i].cha<=minn&&number[i].maxx!=0&&number[i].b!=-1&&pd(i,n)){
                    x=i;minn=number[i].cha;
                }
            }
            sum-=number[x].cha;
            bb--;
            chuli(x);
        }minn=1000005;
        while(cc>n/2){
            for(int i=1;i<=n;++i){
                if(number[i].cha<=minn&&number[i].maxx!=0&&number[i].c!=-1&&pd(i,n)){
                    x=i;minn=number[i].cha;
                }
            }
            sum-=number[x].cha;
            cc--;
            chuli(x);
        }
        cout<<sum<<endl;
    }
    return 0;
}
