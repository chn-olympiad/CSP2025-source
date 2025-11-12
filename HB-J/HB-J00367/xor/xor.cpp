/*#include<bits/stdc++.h>
using namespace std;
int a[1000086],n,k,ans,num[1000086];
int f_xor(int x,int y){
    int sum=0;
    while(x!=0||y!=0){
        cout<<x<<" "<<y;
        int x1=x&1,y1=y&1;
        cout<<"  "<<x1<<" "<<y1<<endl;
        sum<<=1;
        if(x1!=y1)sum++;
        x>>=1;
        y>>=1;
    }
    return sum;
}
int dfs(int pos,int sum,bool zt,int len){
    if(sum==k){
        return len;
    }
    if(pos==n)return 0;
    return max(max(dfs(pos+1,sum,1,),dfs(pos+1,f_xor(sum,a[pos]),0)),dfs(pos+1,f_xor(0,a[pos]),!zt));

}
/*-------------------------------------------------------------*//*
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool f=1,f1=1;
    int s1=0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(a[i]!=1){
            f=0;
            s1++;
            if(a[i]!=0){
                f1=0;
            }
        }

    }
    if(f1&&k==0){
        ans=(n-s1)/2;
        if(f){
            ans=n/2;
        }
    }
    if(f1&&k==1){
        ans=(n-s1);
        if(f){
            ans=n;
        }
    }
    //else ans=max(dfs(1,0,0),dfs(1,0,1));
    cout<<ans;
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
#define ____o int
____o a[1000086],__o,_o_,___o_,num[1000086];
int f_xor(____o _,____o __){
    ____o sum=0;
    while(_!=0||__!=0){
        ____o _1=_&1,__1=__&1;
        sum<<=1;
        if(_1!=__1)sum++;
    }
    return sum;
}
____o main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>__o>>_o_;
    bool f=1,f1=1;
    ____o s1=0;
    for(____o i=1; i<=__o; i++){
        cin>>a[i];
        if(a[i]!=1){
            f=0;
            s1++;
            if(a[i]!=0){
                f1=0;
            }
        }

    }
    if(f1&&_o_==0){
        ___o_=(__o-s1)/2;
        if(f){
            ___o_=__o/2;
        }
    }
    if(f1&&_o_==1){
        ___o_=(__o-s1);
        if(f){
            ___o_=__o;
        }
    }
    cout<<___o_;
    return 0;
}
