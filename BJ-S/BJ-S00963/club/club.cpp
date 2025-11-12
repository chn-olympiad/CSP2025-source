#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,one,two,three,m1[N],m2[N],m3[N];
struct node{
    int s[4],m;
}a[N];
long long ans;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        ans=0;
        one=0;
        two=0;
        three=0;
        //cin>>n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].s[1],&a[i].s[2],&a[i].s[3]);
            //cin>>a[i].s[1]>>a[i].s[2]>>a[i].s[3];
            if(a[i].s[1]>=a[i].s[2]&&a[i].s[1]>=a[i].s[3]){
                ans+=a[i].s[1];
                a[i].m=a[i].s[1]-max(a[i].s[2],a[i].s[3]);
                one++;
                m1[one]=a[i].m;
            }else if(a[i].s[2]>=a[i].s[1]&&a[i].s[2]>=a[i].s[3]){
                ans+=a[i].s[2];
                a[i].m=a[i].s[2]-max(a[i].s[1],a[i].s[3]);
                two++;
                m2[two]=a[i].m;
            }else if(a[i].s[3]>=a[i].s[2]&&a[i].s[3]>=a[i].s[1]){
                ans+=a[i].s[3];
                a[i].m=a[i].s[3]-max(a[i].s[1],a[i].s[2]);
                three++;
                m3[three]=a[i].m;
            }
        }
        //cout<<one<<" "<<two<<" "<<three<<endl;
        if(one>=n/2){
            //sort(m1,1,one);
            for(int i=1;i<one;i++){
                for(int j=i+1;j<=one;j++){
                    if(m1[i]>m1[j])swap(m1[i],m1[j]);
                }
            }
            for(int i=1;i<=one-n/2;i++){
                ans-=m1[i];
            }
        }else if(two>=n/2){
            //sort(m2,1,two);
            for(int i=1;i<two;i++){
                for(int j=i+1;j<=two;j++){
                    if(m2[i]>m2[j])swap(m2[i],m2[j]);
                }
            }
            for(int i=1;i<=two-n/2;i++){
                ans-=m2[i];
            }
        }else if(three>=n/2){
            /*cout<<three<<endl;
            //sort(m3,1,three);
            for(int i=1;i<=three;i++){
                cout<<m3[i]<<" ";
            }*/
            for(int i=1;i<three;i++){
                for(int j=i+1;j<=three;j++){
                    if(m3[i]>m3[j])swap(m3[i],m3[j]);
                }
            }
            /*for(int i=1;i<=three;i++){
                cout<<m3[i]<<" ";
            }*/
            for(int i=1;i<=three-n/2;i++){
                ans-=m3[i];
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
