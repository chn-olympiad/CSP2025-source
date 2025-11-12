#include <bits/stdc++.h>
//include <bits\stdc++.h>
using namespace std;
inline int read(){
    int ans=0,f=1;
    char c=getchar();
    while(c>'9' || c<'0'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans*f;
}

int n,m,a[1005],r;
int x,y;
int erfen(int l1,int r1,int n){
    int ans=2;
    int l=l1,r=r1;
    while(l<=r){
        int mid=(r-l)/2+l;
        if(a[mid]<=n){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }

    }
    return ans;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        a[i]=read();
    }
    r=a[1];
    sort(a+1,a+n*m+1);
    int p=erfen(1,n*m,r);
    p=m*n-p+1;
    x=p/m;
    if(p%m!=0) x+=1;
    if(x%2==1){
        y=p-(x-1)*m;
    }
    else{
        y=x*m-p;
        y=m-y+1;
    }
    cout << x << " " << y << endl;
    //cout << p << endl;
    /*for(int i=1;i<=n*m;i++){
        cout << a[i] << endl;
    }*/
    return 0;
}
