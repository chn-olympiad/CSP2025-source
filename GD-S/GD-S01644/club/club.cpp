#include<bits/stdc++.h>
using namespace std;
int T,n,ans1,ans2,x[1000005],a[1000005][3],y,z,maxx;
int cnt1,cnt2,cnt3;
bool cmp(int p,int q){
    return p>q;
}
struct node{
    int l,r;
};
int main(){
//     freopen("club.in","r",stdin);
//     freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        ans1=0;
        ans2=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][1]==0&&a[i][2]==0){
                ans1++;
            }else if(a[i][2]==0){
                ans2++;
            }
        }if(ans1==n){ // 特殊性质A
            for(int i=1;i<=n;i++){
                x[i]=a[i][0];
            }
            sort(x+1,x+1+n,cmp);
            y=0;
            z=0;
            for(int i=1;i<=n;i++){
                if(y+1<=n/2){
                    y++;
                    z+=x[i];
                }else{
                    break;
                }
            }
            cout<<z<<endl;
        }else if(ans2==n){ // 特殊性质B
            //
        }else if(n==2){
            int r1,s1,t1,r2,s2,t2;
            r1=a[1][0];
            s1=a[1][1];
            t1=a[1][2];
            r2=a[2][0];
            s2=a[2][1];
            t2=a[2][2];
            maxx=max(max(r1+s2,max(r1+t2,max(s1+r2,s1+t2))),max(t1+r2,t1+s2));
            cout<<maxx<<endl;
        }else{
            cnt1=0;
            cnt2=0;
            cnt3=0;
            for(int i=1;i<=n;i++){
                if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]&&cnt1+1<=n/2){
                    cnt1++;
                    z+=a[i][0];
                }else if(a[i][1]>a[i][2]&&cnt2+1<=n/2){
                    cnt2++;
                    z+=a[i][1];
                }else{
                    cnt3++;
                    z+=a[i][2];
                }if(a[i][1]>a[i][0]&&a[i][1]>a[i][2]&&cnt2+1<=n/2){
                    cnt2++;
                    z+=a[i][1];
                }else if(a[i][0]>a[i][2]&&cnt1+1<=n/2){
                    cnt1++;
                    z+=a[i][0];
                }else{
                    cnt3++;
                    z+=a[i][2];
                }if(a[i][2]>a[i][0]&&a[i][2]>a[i][1]&&cnt3+1<=n/2){
                    cnt3++;
                    z+=a[i][2];
                }else if(a[i][0]>a[i][1]&&cnt1+1<=n/2){
                    cnt1++;
                    z+=a[i][0];
                }else{
                    cnt2++;
                    z+=a[i][1];
                }
            }
            cout<<z<<endl;
        }
    }
    return 0;
}
