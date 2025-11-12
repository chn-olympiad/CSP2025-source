#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int t;
struct member{
    int a1;
    int a2;
    int a3;
}a[maxn];
bool cmp(member b,member c){
    if(b.a1!=c.a1){
        if(b.a2!=0&&c.a2!=0){
            if(b.a1==0){
                return b.a1>c.a1;
            }else if(c.a1==0){
                return b.a1<c.a1;
            }else{
                return b.a1>c.a1;
            }
        }else if(b.a2==0){
            return b.a2>c.a2;
        }else if(c.a2==0){
            return b.a2<c.a2;
        }
    }else if(b.a2!=c.a2){
        if(b.a3!=0&&c.a3!=0){
            if(b.a2==0){
                return b.a2>c.a2;
            }else if(c.a2==0){
                return b.a2<c.a2;
            }else{
                return b.a2>c.a2;
            }
        }else if(b.a3==0){
            return b.a3>c.a3;
        }else if(c.a3==0){
            return b.a3<c.a3;
        }
    }else{
        if(b.a3==0){
            return b.a3>c.a3;
        }else if(c.a3==0){
            return b.a3<c.a3;
        }else{
            return b.a3>c.a3;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ll sum=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n/2;i++){
            sum=sum+a[i].a1;
        }
        bool flag=false;
        int temp=n/2+1;
        int ret=n-n/2;
        for(int i=temp;i<=temp+ret/2-1;i++){
            if(i==temp+ret/2-1){
                if(a[i+1].a2==a[i].a2){
                    sum=sum+a[i+1].a2;
                    flag=true;
                }
            }
            sum=sum+a[i].a2;
        }
        if(flag==true){
            cout<<sum<<endl;
            continue;
        }
        for(int i=temp+ret/2;i<=n;i++){
            sum=sum+a[i].a3;
        }
        cout<<sum<<endl;
    }
    return 0;
}
