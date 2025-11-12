#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--){
        int a[100005],b[100005],c[100005],x[100005],y[100005],z[100005],d[100005];
        int g[100005];
        int p=0,q=0,r=0;int s=0,u=0,v=0;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i];
        for(int i=0;i<n;i++){
            if(b[i]>=c[i]){
                if(a[i]>=b[i]){p++;u++;x[i]=a[i];y[i]=b[i];z[i]=x[i]-y[i];d[i]=1;}
                else if(a[i]>=c[i]){q++;s++;x[i]=b[i];y[i]=a[i];z[i]=x[i]-y[i];d[i]=2;}
                else{q++;v++;x[i]=b[i];y[i]=c[i];z[i]=x[i]-y[i];d[i]=2;}
            }
            else {
                if(a[i]>=c[i]){p++;v++;x[i]=a[i];y[i]=c[i];z[i]=x[i]-y[i];d[i]=1;}
                else if(a[i]>=b[i]){r++;s++;x[i]=c[i];y[i]=a[i];z[i]=x[i]-y[i];d[i]=3;}
                else{r++;u++;x[i]=c[i];y[i]=b[i];z[i]=x[i]-y[i];d[i]=3;}
            }
        }
        int f=n/2,ans=0,e=0;
        for(int i=0;i<n;i++)ans=ans+x[i];
        if(p<=f&&q<=f&&r<=f){
            cout<<ans<<endl;
        }
        else if(p>f){
            for(int i=0;i<n;i++){
                if(d[i]==1){g[e]=z[i];e++;}
                int l=e-1;
                while(l>0){
                    if(g[l]<g[l-1]){
                        int h=g[l];
                        g[l]=g[l-1];
                        g[l-1]=h;
                    }
                    l--;
                }
            }
            for(int i=0;i<p-f;i++){
                ans=ans-g[i];
            }
            cout<<ans<<endl;
        }
        else if(q>f){
            for(int i=0;i<n;i++){
                if(d[i]==2){g[e]=z[i];e++;}
                int l=e-1;
                while(l>0){
                    if(g[l]<g[l-1]){
                        int h=g[l];
                        g[l]=g[l-1];
                        g[l-1]=h;
                    }
                    l--;
                }
            }
            for(int i=0;i<q-f;i++){
                ans=ans-g[i];
            }
            cout<<ans<<endl;
        }
        else if(r>f){
            for(int i=0;i<n;i++){
                if(d[i]==3){g[e]=z[i];e++;}
                int l=e-1;
                while(l>0){
                    if(g[l]<g[l-1]){
                        int h=g[l];
                        g[l]=g[l-1];
                        g[l-1]=h;
                    }
                    l--;
                }
            }
            for(int i=0;i<r-f;i++){
                ans=ans-g[i];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

