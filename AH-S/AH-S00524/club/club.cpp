#include<bits/stdc++.h>
using namespace std;
// Ren5Jie4Di4Ling5%
struct cy{
	int w1,w2,w3;
}a[100005];
cy b1[100005],b2[100005],b3[100005];
int c[5],n,m,t;
bool cmp1(cy x,cy y){
    int k=x.w1-max(x.w2,x.w3);
    int k2=y.w1-max(y.w2,y.w3);
    return k>=k2;
}
bool cmp2(cy x,cy y){
    int k=x.w2-max(x.w1,x.w3);
    int k2=y.w2-max(y.w1,y.w3);
    return k>=k2;
}
bool cmp3(cy x,cy y){
    int k=x.w3-max(x.w2,x.w1);
    int k2=y.w3-max(y.w2,y.w1);
    return k>=k2;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a)); memset(c,0,sizeof(c));
        memset(b1,0,sizeof(b1)); memset(b2,0,sizeof(b2));
        memset(b3,0,sizeof(b3)); 
        cin>>n; long long ans=0;
        for(int i=1;i<=n;i++)
            cin>>a[i].w1>>a[i].w2>>a[i].w3;
        for(int i=1;i<=n;i++){
            int k=max(a[i].w1,max(a[i].w2,a[i].w3));
            if(k==a[i].w1) {
                ans+=a[i].w1; c[1]++;
                b1[c[1]].w1=a[i].w1;
                b1[c[1]].w2=a[i].w2;
                b1[c[1]].w3=a[i].w3;
            }
            if(k==a[i].w2&&k!=a[i].w1) {
                ans+=a[i].w2; c[2]++;
                b2[c[2]].w1=a[i].w1;
                b2[c[2]].w2=a[i].w2;
                b2[c[2]].w3=a[i].w3;
            }
            if(k==a[i].w3&&k!=a[i].w1&&k!=a[i].w2) {
                ans+=a[i].w3; c[3]++;
                b3[c[3]].w1=a[i].w1;
                b3[c[3]].w2=a[i].w2;
                b3[c[3]].w3=a[i].w3;
            }
        }
        if(c[1]>n/2) m=1;
        if(c[2]>n/2) m=2;
        if(c[3]>n/2) m=3;
        if(m==0) cout<<ans<<endl;
        else{
            if(m==1){
                sort(b1+1,b1+c[1]+1,cmp1);
                for(int i=c[1];i>n/2;i--)
					ans+=max(b1[i].w2,b1[i].w3)-b1[i].w1;
            }
            if(m==2){
                sort(b2+1,b2+c[2]+1,cmp2);
                for(int i=c[2];i>n/2;i--)
					ans+=max(b2[i].w3,b2[i].w1)-b2[i].w2;
            }
            if(m==3){
                sort(b3+1,b3+c[3]+1,cmp3);
                for(int i=c[3];i>n/2;i--)
					ans+=max(b3[i].w2,b3[i].w1)-b3[i].w3;
            }
            cout<<ans<<endl;
        }
    }
    fclose(stdin); fclose(stdout);
    return 0;
}
