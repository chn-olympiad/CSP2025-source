#include <bits/stdc++.h>

using namespace std;
const int N=100001;
struct p
{
    int amax,ax;
    int bmax;
}a[N];
int c[N];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t){
        int n,sum=0;
        cin>>n;
        int b[4]={0,0,0,0};
        for(int i=1;i<=n;i++){
            int a1,a2,a3;
            cin>>a1>>a2>>a3;
            if(a1>=a2&&a1>=a3){
                a[i].amax=a1;
                a[i].ax=min(a1-a2,a1-a3);
                a[i].bmax=1;
                b[1]++;
            }
            else if(a2>=a3){
                a[i].amax=a2;
                a[i].ax=min(a2-a1,a2-a3);
                a[i].bmax=2;
                b[2]++;
            }
            else {
                a[i].amax=a3;
                a[i].ax=min(a3-a1,a3-a2);
                a[i].bmax=3;
                b[3]++;
            }
            sum+=a[i].amax;
        }
        for(int i=1;i<=3;i++){
            if(b[i]-n/2>0){
                int s=0;
                for(int j=1;j<=n;j++){
                    if(a[j].bmax==i){
                        c[s]=a[j].ax;
                        s++;
                    }
                }
                sort(c,c+b[i]);
                for(int j=0;j<b[i]-n/2;j++){
                    sum-=c[j];
                }
            }
        }
        cout<<sum<<endl;
        t--;
    }


    return 0;
}
