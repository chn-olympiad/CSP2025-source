#include<bits/stdc++.h>
using namespace std;
/*int b[5050];
void qp(int ks,int js,int sl){
    if(ks==0){
        for(int i=1;i<=5050;i++){
            if(b[i]==1) cout<<i;
        }
        cout<<endl;
        return;
    }
    for(int i=ks;i<=js;i++){
        int cnt=1;
        while(b[cnt]==1&&cnt<=js) cnt++;
        if(cnt>js||cnt==sl) return;
        b[cnt]=1;
        qp(i-1,js,cnt);
        sl=cnt;
        b[cnt]=0;
    }

}*/
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5050];
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    //qp(3,n,0);
    if(n==3){
        if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cout<<1;
        else cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
