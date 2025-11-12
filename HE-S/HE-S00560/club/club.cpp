#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],lmt,oNum,num1,num2,num3;
struct mbr{
    int h,d;
}mx[100005],o[100005];
bool zero,flag;
long long ans;
bool cmp(mbr a,mbr b){
    return a.h>b.h;
}int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        memset(a,0,sizeof a);
        memset(mx,0,sizeof mx);
        memset(o,0,sizeof o);
        lmt=n/2,oNum=num1=num2=num3=ans=zero=flag=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            for(int j=1;j<=3;j++){
                if(!a[i][j]){
                    zero=1;
                    oNum++;
                    break;
                }
            }for(int j=1;j<=3;j++){
                if(a[i][j]){
                    if(zero){
                        if(o[i].h<a[i][j]){
                            o[i].h=a[i][j];
                            o[i].d=j;
                            a[i][j]=0;
                        }
                    }else{
                        if(mx[i].h<a[i][j]){
                            mx[i].h=a[i][j];
                            mx[i].d=j;
                        }
                    }
                }
            }zero=0;
        }sort(mx+1,mx+n-oNum+1,cmp);
        sort(o+1,o+oNum+1,cmp);
        for(int i=1;i<=oNum;i++){
            if(num1==lmt&&num2==lmt&&num3==lmt)break;
            flag=0;
            if(o[i].d==1&&num1<lmt){
                ans+=o[i].h;
                num1++;
                flag=1;
            }else if(!flag&&o[i].d==2&&num2<lmt){
                ans+=o[i].h;
                num2++;
                flag=1;
            }else if(!flag&&o[i].d==3&&num3<lmt){
                ans+=o[i].h;
                num3++;
                flag=1;
            }else{
                if(a[i][2]>a[i][3]){
                    if(!flag&&num2<lmt){
                        ans+=a[i][2];
                        num2++;
                        flag=1;
                    }else if(!flag&&num3<lmt){
                        ans+=a[i][3];
                        num3++;
                        flag=1;
                    }
                }else{
                    if(!flag&&num3<lmt){
                        ans+=a[i][3];
                        num3++;
                        flag=1;
                    }else if(!flag&&num2<lmt){
                        ans+=a[i][2];
                        num2++;
                        flag=1;
                    }
                }
            }
        }for(int i=1;i<=n-oNum;i++){
            if(num1==lmt&&num2==lmt&&num3==lmt)break;
            flag=0;
            if(mx[i].d==1&&num1<lmt){
                ans+=mx[i].h;
                num1++;
                flag=1;
            }else if(!flag&&mx[i].d==2&&num2<lmt){
                ans+=mx[i].h;
                num2++;
                flag=1;
            }else if(!flag&&mx[i].d==3&&num3<lmt){
                ans+=mx[i].h;
                num3++;
                flag=1;
            }else{
                if(a[i][2]>a[i][3]){
                    if(!flag&&num2<lmt){
                        ans+=a[i][2];
                        num2++;
                        flag=1;
                    }else if(!flag&&num3<lmt){
                        ans+=a[i][3];
                        num3++;
                        flag=1;
                    }
                }else{
                    if(!flag&&num3<lmt){
                        ans+=a[i][3];
                        num3++;
                        flag=1;
                    }else if(!flag&&num2<lmt){
                        ans+=a[i][2];
                        num2++;
                        flag=1;
                    }
                }
            }
        }cout<<ans<<'\n';
    }return 0;
}
