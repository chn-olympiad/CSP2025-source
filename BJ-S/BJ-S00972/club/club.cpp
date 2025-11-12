#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n;
int a[100005][5],maxn[100005],cha[5][100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        int t1=0,t2=0,t3=0,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            int _1=a[i][1],_2=a[i][2],_3=a[i][3];
            maxn[i]=max(_1,max(_2,_3));
            if(_1>=_2&&_1>=_3){
                cha[1][++t1]=maxn[i]-max(_2,_3);
            }else if(_2>=_3){
                cha[2][++t2]=maxn[i]-max(_1,_3);
            }else{
                cha[3][++t3]=maxn[i]-max(_1,_2);
            }
            ans+=maxn[i];
        }
        //cout<<ans<<endl;
        if(t1>n/2){
            // cout<<"11111111111\n";
            sort(cha[1]+1,cha[1]+t1+1);
            for(int i=1;t1-i+1>n/2;++i){
                ans-=cha[1][i];//cout<<cha[1][i]<<" ";
            }
        }if(t2>n/2){
            // cout<<"2222222222222\n";
            sort(cha[2]+1,cha[2]+t2+1);
            for(int i=1;t2-i+1>n/2;++i){
                ans-=cha[2][i];//cout<<cha[2][i]<<" ";
            }
        }if(t3>n/2){
            // cout<<"3333333333333\n";
            sort(cha[3]+1,cha[3]+t3+1);
            for(int i=1;t3-i+1>n/2;++i){
                ans-=cha[3][i];//cout<<cha[3][i]<<" ";
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}/*
先贪心选取，若有>n/2则顺序踢出
*/