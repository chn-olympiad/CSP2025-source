#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        int ans=0;
        int a[100000];
        int b[100000];
        int c[100000];
        int s1=0;
        int s2=0;
        int s3=0;
        for(int i=1;i<=n;i++){
                cin>>a[i]>>b[i]>>c[i];
        }
        for(int i=1;i<=n;i++){
            if(a[i]>b[i]&&a[i]>c[i]){
                s1+=1;
            }if(b[i]>a[i]&&b[i]>c[i]){
                s2+=1;
            }if(c[i]>b[i]&&c[i]>a[i]){
                s3+=1;
            }
              int s=max(a[i],b[i]);  
              int h=max(s,c[i]);
              ans+=h;
        }
            if((s1<=n/2)&&(s2<=n/2)&&(s3<=n/2)){
               cout<<ans<<endl; 
               return 0;
            }
            else if(s1>n/2){
                for(int i=1;i<=n;i++){
                    if(b[i]>=c[i]){
                    int d=a[i]-b[i];
                    int e=max(a[i+1],b[i+1]);  
                    int f=max(e,c[i+1]);
                    if(d<f){
                         if((a[i-1]==a[i])&&(b[i-1]==b[i])&&(c[i-1]==c[i])){
                             ans-=a[i]*2;
                         }
                        else ans-=a[i];
                        ans+=b[i];
                    }
             }
            else if(c[i]>b[i]){
                int d=a[i]-c[i];
                    int e=max(a[i+1],b[i+1]);  
                    int f=max(e,c[i+1]);
                    if(d<f){
                        ans-=a[i];
                        ans+=c[i];
                    }
            }
        }
    }
       else if(s2>n/2){
                for(int i=1;i<=n;i++){
                    if(a[i]>=c[i]){
                    int d=b[i]-a[i];
                    int e=max(a[i+1],b[i+1]);  
                    int f=max(e,c[i+1]);
                    if(d<f){
                        if((a[i-1]==a[i])&&(b[i-1]==b[i])&&(c[i-1]==c[i])){
                            ans-=b[i]*2;
                        }
                        else ans-=b[i];
                        ans+=a[i];
                    }
             }
            else if(c[i]>a[i]){
                int d=b[i]-c[i];
                    int e=max(a[i+1],b[i+1]);  
                    int f=max(e,c[i+1]);
                    if(d<f){
                        ans-=b[i];
                        ans+=c[i];
                    }
            }
        }
    }
    else if(s3>n/2){
                for(int i=1;i<=n;i++){
                    if(a[i]>=b[i]){
                    int d=c[i]-a[i];
                    int e=max(a[i+1],b[i+1]);  
                    int f=max(e,c[i+1]);
                    if(d<f){
                         if((a[i-1]==a[i])&&(b[i-1]==b[i])&&(c[i-1]==c[i])){
                             ans-=c[i]*2;
                         }
                        else ans-=c[i];
                        ans+=a[i];
                    }
             }
            else if(b[i]>a[i]){
                int d=c[i]-b[i];
                    int e=max(a[i+1],b[i+1]);  
                    int f=max(e,c[i+1]);
                    if(d<f){
                        ans-=c[i];
                        ans+=b[i];
                    }
            }
        }
        
    }
    cout<<ans<<endl;
}
    return 0;
}