#include<bits/stdc++.h>
using namespace std;
int read(){
    int n=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        n=(n<<3)+(n<<1)+(ch^48);
        ch=getchar();
    }
    return n*f;
}
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    n=read();
    m=read();
    for(int i=1;i<=n*m;i++) a[i]=read();
    int k=a[1];
    sort(a+1,a+n*m+1,cmp);
    int cnt=1;
    for(int j=1;j<=m;j++){//cross
        if(j%2==1){//from up to down
            for(int i=1;i<=n;i++){
                if(a[cnt]==k){
                    cout<<j<<" "<<i<<endl;
                    return 0;
                }
                cnt++;
            }
        }else{//from down to up
            for(int i=n;i>=1;i--){
                if(a[cnt]==k){
                    cout<<j<<" "<<i<<endl;
                    return 0;
                }
                cnt++;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
