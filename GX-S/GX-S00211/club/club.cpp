#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long t,n,a[N],b[N],c[N];
bool flag1 = true,flag2 = true;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        long long p[N],p1[N],p2[N],p3[N];
        long long ans = 0;
        long long a1 = 0,b1 = 0,c1 = 0;
        for(int i = 1;i<=n;i++){
            int maxx = 0;
            cin>>a[i]>>b[i]>>c[i];
            p3[i] = b[i]-a[i];
            p[i] = a[i]-b[i];
            p1[i]= a[i]-c[i];
            p2[i]= b[i]-c[i];
            if(b[i]!=0) flag2 = false;
            if(c[i]!=0) flag1 = false;

        }
        if(flag1&&flag2){
            sort(a+1,a+1+n);
            for(int i = n;i>n/2;i--) ans+=a[i];
        }
        else if(flag1&&!flag2){
            for(int i = 1;i<=n;i++){
                ans+=max(a[i],b[i]);
                if(a[i]>b[i]) a1++;
                else b1++;
            }
            if(a1>n/2){
                int i = 0;
                sort(p+1,p+n+1);
                while(a1>n/2){
                    i++;
                    if(p[i]>0){
                        ans-=p[i];
                        a1-=1;
                    }
                    if(a1==n/2) break;
                }
            }
            else if(b1>n/2){
                sort(p3+1,p3+1+n);
                int i = 0;
                while(b1>n/2){
                    i++;
                    if(p3[i]>=0){
                        ans-=p3[i];
                        b1-=1;
                    }
                    if(b1<=n/2) break;
                }
            }
        }
        else{
        for(int i = 1;i<=n;i++){
            ans+=max(a[i],max(b[i],c[i]));
            if(a[i]>=b[i]&&a[i]>=c[i]) a1++;
            else if(b[i]>=a[i]&&b[i]>=c[i]) b1++;
            else c1++;
        }
        sort(p+1,p+1+n);
        sort(p1+1,p1+1+n);
        sort(p2+1,p2+1+n);
        int i = 0;
        if(a1>n/2){
            while(a1>n/2){
                i++;
                if(p[i]<p1[i]&&p[i]>=0&&p1[i]>=0){
                    if(b1<n/2){
                        b1++;
                        a1--;
                        ans-=p[i];
                    }
                    else{
                        c1++;
                        a1--;
                        ans-=p1[i];
                    }
                }
                else{
                    if(b1<n/2){
                        b1++;
                        a1--;
                        ans-=p[i];
                    }
                    else{
                        c1++;
                        a1--;
                        ans-=p1[i];
                    }
                }
            }
        }
        else if(b1>n/2){
            while(b1>n/2){
                i++;
                if(p2[i]<p3[i]&&p2[i]>=0&&p3[i]>=0){
                    if(a1<n/2){
                        a1++;
                        b1--;
                        ans-=p2[i];
                    }
                    else{
                        c1++;
                        b1--;
                        ans-=p3[i];
                    }
                }
                else{
                    if(c1<n/2){
                        c1++;
                        b1--;
                        ans-=p2[i];
                    }
                    else{
                        a1++;
                        b1--;
                        ans-=p3[i];
                    }
                }
            }
        }
        else if(c1>n/2){
            while(c1>n/2){
                i++;
                if(p1[i]<p2[i]&&p1[i]<=0&&p2[i]<=0){
                    if(a1<n/2){
                        a1++;
                        c1--;
                        ans+=p1[i];
                    }
                    else{
                        c1--;
                        b1++;
                        ans+=p2[i];
                    }
                }
                else{
                    if(b1<n/2){
                        b1++;
                        c1--;
                        ans+=p1[i];
                    }
                    else{
                        a1--;
                        b1++;
                        ans+=p2[i];
                    }
                }
            }
        }
        }
        cout<<ans<<endl;
        }
        return 0;
}
