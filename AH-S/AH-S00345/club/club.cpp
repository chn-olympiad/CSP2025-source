#include <bits/stdc++.h>
using namespace std;
struct p{
    int a1;
    int a2;
    int a3;
};
bool cmp(p x,p y){
    return x.a1>y.a1;
}

int t;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        p a[100005];


        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;

        }
        sort(a+1,a+n+1,cmp);
        int k=0,sum1=0,sum2=0;
        for(int i=1;i<=n;i++){
            if(a[i].a1>a[i].a2){
                sum1+=a[i].a1;
                k++;
            }
            sum2+=a[i].a2;

        }
        if(k>n/2){
            int r=n;
            while(k>n/2){
                if(a[r].a1>a[r].a2){
                    k--;

                    sum1-=a[r].a1;
                    sum2+=a[r].a2;
                }
                r--;
            }

        }
        cout<<sum1+sum2<<endl;


    }

    return 0;
}
