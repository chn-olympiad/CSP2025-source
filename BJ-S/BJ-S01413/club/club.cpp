#include <bits/stdc++.h>
using namespace std;
struct node{
    int b1,b2,b3,cha;
}a[100005],bg1[100005],bg2[100005],bg3[100005];
bool cmp(node xx,node yy){
    return xx.cha>=yy.cha;
}
int main(){
    ios::sync_with_stdio(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int cnt1,cnt2,cnt3,sum1,sum2,sum3;
        cnt1=cnt2=cnt3=sum1=sum2=sum3=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].b1>>a[i].b2>>a[i].b3;
            if (a[i].b1>=a[i].b2&&a[i].b1>=a[i].b3){
                bg1[++cnt1].b1=a[i].b1;
                sum1+=a[i].b1;
                if (a[i].b2>=a[i].b3){
                    bg1[cnt1].cha=a[i].b1-a[i].b2;
                }
                else{
                    bg1[cnt1].cha=a[i].b1-a[i].b3;
                }
            }
            else if (a[i].b2>=a[i].b1&&a[i].b2>=a[i].b3){
                bg2[++cnt2].b2=a[i].b2;
                sum2+=a[i].b2;
                if (a[i].b1>=a[i].b3){
                    bg2[cnt2].cha=a[i].b2-a[i].b1;
                }
                else{
                    bg2[cnt2].cha=a[i].b2-a[i].b3;
                }
            }
            else{
                bg3[++cnt3].b3=a[i].b3;
                sum3+=a[i].b3;
                if (a[i].b1>=a[i].b2){
                    bg3[cnt3].cha=a[i].b3-a[i].b1;
                }
                else{
                    bg3[cnt3].cha=a[i].b3-a[i].b2;
                }
            }
        }
        if (cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
            cout<<sum1+sum2+sum3<<endl;
        }
        else{
            if(cnt1>n/2){
                sort(bg1+1,bg1+cnt1+1,cmp);
                for (int i=n/2+1;i<=cnt1;i++){
                    sum1-=bg1[i].cha;
                }
            }
            else if(cnt2>n/2){
                sort(bg2+1,bg2+cnt2+1,cmp);
                for (int i=n/2+1;i<=cnt2;i++){
                    sum2-=bg2[i].cha;
                }
            }
            else{
                sort(bg3+1,bg3+cnt3+1,cmp);
                for (int i=n/2+1;i<=cnt3;i++){
                    sum3-=bg3[i].cha;
                }
            }
            cout<<sum1+sum2+sum3<<endl;
        }
    }
    return 0;
}