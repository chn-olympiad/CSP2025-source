#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
bool cmp(int qweasd,int asdzxc){
    return qweasd<asdzxc;
}
int C(int up,int down){
    int fz=1,fm=1;
    int flag;
    flag=down;
    for(int i=1;i<=up;i++){
        fz=fz*flag;
        flag--;
    }flag=up;
    for(int i=1;i<=up;i++){
        fm=fm*flag;
        flag--;
    }
    //cout<<fm<<" "<<fz<<" ";
    return fz/fm;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1,cmp);
    //36'
    int ans=0;
    if(a[1]==a[n] && a[1]==1){
		//cout<<"if1"<<" ";
        for(int i=3;i<=n;i++){
            ans+=C(i,n);
            //cout<<ans<<endl;
        }cout<<ans;
    }else if(n<=2) cout<<0;
    else{
        //12
        if(a[1]+a[2]+a[3]>a[3]*2)cout<<1;
        else cout<<0;
    }
    return 0;
}