#include<bits/stdc++.h>
using namespace std;
const int N=100100;
struct student{
    int a,b,c;//贡献度
    int flag;
}stu[N];
int n;
struct club{
    int p;//第i个人
    int a,b,c;
}a[N],b[N],c[N];
//int a[N],b[N],c[N];
int cnta,cntb,cntc;
bool cmp1(int a,int b){
    return a>b;
}
int flag1=0,flag2=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        flag1=flag2=0;
        int cnta=0,cntb=0,cntc=0;
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            a[i].a=a[i].b=a[i].c=0;
            b[i].a=b[i].b=b[i].c=0;
            c[i].a=c[i].b=c[i].c=0;
        }
        for(int i=1;i<=n;i++){
            cin>>stu[i].a>>stu[i].b>>stu[i].c;
            if(stu[i].b!=0||stu[i].c!=0) flag1=1;
            if(stu[i].c!=0) flag2=1;
        }
        for(int i=1;i<=n;i++){
            if(stu[i].a>stu[i].b&&stu[i].a>stu[i].c) stu[i].flag=1;
            else if(stu[i].b>stu[i].a&&stu[i].b>stu[i].c) stu[i].flag=2;
            else if(stu[i].c>stu[i].a&&stu[i].c>stu[i].b) stu[i].flag=3;
            else stu[i].flag=3;
        }

        int k1=0,k2=0,k3=0;
        for(int i=1;i<=n;i++){
            if(stu[i].flag==1){
                    k1++;
                    a[k1].p=i;
                    a[k1].c=stu[i].a;
                    cnta+=a[k1].c;
                    a[k1].a=stu[i].a;
                    a[k1].b=stu[i].b;
                    a[k1].c=stu[i].c;


            }
            if(stu[i].flag==2){
                    k2++;
                    b[k2].p=i;
                    b[k2].c=stu[i].b;
                    cntb+=b[k2].c;
                    b[k2].a=stu[i].a;
                    b[k2].b=stu[i].b;
                    b[k2].c=stu[i].c;

            }
            if(stu[i].flag==3){
                    k3++;
                    c[k3].p=i;
                    c[k3].c=stu[i].c;
                    cntc+=c[k3].c;
                    c[k3].a=stu[i].a;
                    c[k3].b=stu[i].b;
                    c[k3].c=stu[i].c;


            }
        }
        ans=cnta+cntb+cntc;
        int ansmax_now=0;
        int ansmax_last=0;
        int w[N]={0};
        int res=0;
        //cout<<flag1<<endl;
        //cout<<k1<<" "<<k2<<" "<<k3<<endl;
            if(flag1==0){
                for(int i=1;i<=n;i++){
                    w[i]=a[i].a;
                }
                sort(w+1,w+n+1,cmp1);
                for(int i=1;i<=n/2;i++){
                    res+=w[i];
                }
                cout<<res;
                continue;
            }
        if(k1>n/2){//开始踢人
            for(int j=1;j<=k1-n/2;j++){
            for(int i=1;i<=k1;i++){
                    //cout<<i<<" ";
                if(a[i].b>a[i].c){//若a社团的第i个人在b影响比c大
                    ansmax_now=ans-a[i].a+a[i].b;
                    //cout<<"????";
                }
                else if(a[i].b<a[i].c){
                    ansmax_now=ans-a[i].a+a[i].c;
                    //cout<<"????";
                }
                else{ ansmax_now=ans-a[i].a+a[i].b;
                //cout<<"????";
                }
                if(ansmax_now>ansmax_last){
                        ansmax_last=ansmax_now;
                }
            }
        }
        }
        else if(k2>n/2){//开始踢人
            //cout<<"??????";
            int t=k2-n/2;
            for(int i=1;i<=k2;i++){
                while(t=0){
                //cout<<b[i].a<<" "<<b[i].c<<endl;
                if(b[i].a>b[i].c){//若a社团的第i个人在b影响比c大
                    ansmax_now=ans-b[i].b+b[i].a;
                    //cout<<"??????";
                }
                else if(b[i].a<b[i].c){
                    ansmax_now=ans-b[i].b+b[i].c;
                }
                else{
                    ansmax_now=ans-b[i].b+b[i].a;
                    //cout<<ansmax_now<<endl;
                    //cout<<"????"<<endl;
                }
                if(ansmax_now>ansmax_last){
                        ansmax_last=ansmax_now;
                        t--;
                }
            }
        }
        }
        else if(k3>n/2){//开始踢人
            for(int j=1;j<=k3-n/2;j++){
            for(int i=1;i<=k3;i++){
                if(c[i].a>c[i].b){//若a社团的第i个人在b影响比c大
                    ansmax_now=ans-c[i].c+c[i].a;
                }
                else if(c[i].a<c[i].b){
                    ansmax_now=ans-c[i].c+c[i].b;
                }
                else ansmax_now=ans-c[i].c+c[i].a;
                if(ansmax_now>ansmax_last){
                        ansmax_last=ansmax_now;
                }
            }
        }
        }
        else{
            cout<<ans<<endl;
            continue;
        }
        cout<<ansmax_last<<endl;
        //cout<<ans<<endl;
        }
    return 0;
}
