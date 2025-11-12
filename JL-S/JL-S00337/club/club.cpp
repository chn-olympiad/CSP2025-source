#include <bits/stdc++.h>
using namespace std;
int T,n,cnt1,cnt2,cnt3,ans;
const int MAX=1e5+10;
struct man{
    int i;
    int a,b,c;
    int k;
    int m;
    bool operator< (const man& n)const{
        bool rt;
        if(k==n.k&&m==n.m){
            switch(m){
                case 1:{rt=a>n.a;break;}
                case 2:{rt=b>n.b;break;}
                case 3:{rt=c>n.c;break;}
            }
        }else   rt=k<n.k;
        return rt;
    }
    void mk(){
        if(a<=b&&b<=c){k=a-c+b-c;m=3;}
        if(a<=c&&c<=b){k=a-b+c-b;m=2;}
        if(b<=a&&a<=c){k=a-c+b-c;m=3;}
        if(b<=c&&c<=a){k=c-a+b-a;m=1;}
        if(c<=a&&a<=b){k=a-b+c-b;m=2;}
        if(c<=b&&b<=a){k=c-a+b-a;m=1;}
    }
};
man a[MAX];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        cnt1=0;
        cnt2=0;
        cnt3=0;
        for(int i=0;i<n;i++){
            a[i].i=i;
            cin>>a[i].a>>a[i].b>>a[i].c;
            a[i].mk();
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){
            if(a[i].m==1){
                if(cnt1<n/2){
                    cnt1++;
                    ans+=a[i].a;
                }else{
                    if(a[i].b>a[i].c||cnt3<n/2){
                        cnt2++;
                        ans+=a[i].b;
                    }else{
                        cnt3++;
                        ans+=a[i].c;
                    }
                }
            }
            if(a[i].m==2){
                if(cnt2<n/2){
                    cnt2++;
                    ans+=a[i].b;
                }else{
                    if(a[i].a>a[i].c||cnt3<n/2){
                        cnt1++;
                        ans+=a[i].a;
                    }else{
                        cnt3++;
                        ans+=a[i].c;
                    }
                }
            }
            if(a[i].m==3){
                if(cnt3<n/2){
                    cnt3++;
                    ans+=a[i].c;
                }else{
                    if(a[i].b>a[i].a||cnt1<n/2){
                        cnt2++;
                        ans+=a[i].b;
                    }else{
                        cnt1++;
                        ans+=a[i].a;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}