#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,s,u,v,r;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    int t=m*n;
    sort(a+1,a+t+1,cmp);
    for(int i=1;i<=t;i++){
            //cout<<a[i]<<" ";
        if(r==a[i]){
            s=i;
            //cout<<s;
            break;
        }
    }
    while(s>n){
        s-=n;
        u++;
    }
    if(u%2==0){
        v=s;
        cout<<u+1<<" "<<s;
    }else if(u%2!=0){
        cout<<u+1<<" "<<n-s+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

//#Shang4Shan3Ruo6Shui4
