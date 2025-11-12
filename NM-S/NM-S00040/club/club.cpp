#include<iostream>
#include<cmath> 
#include<algorithm>
#define rc 114514
using namespace std;
int like[rc][3],choose[rc]={0};
int solve0(int n,const int max_p){
    int ans=-1,count=pow(3,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++) cin>>like[i][j];
    }
    for(int strgh=0,i=0;i<count;strgh=0,i++){
        int wei=n-1,jin=0,door[3]={0,0,0};choose[wei]++;
        while(wei>=0){
            if(choose[wei]+jin>2){
                jin=1,choose[wei]=0,wei--;
            }else{
                choose[wei]=choose[wei]+jin;
                jin=0;break;
            }
        }
        for(int j=0;j<n;j++) door[choose[j]]++;
        if(door[0]>max_p||door[1]>max_p||door[2]>max_p) continue;
        for(int j=0;j<n;j++){
            strgh+=like[j][choose[j]];
        }
        if(strgh>ans) ans=strgh;
    }
    
    return ans;
}
int solve1(int n,const int real_n){
    int ans=-1,like[rc],cnt=0;
    for(int i=0,b,c;i<n;i++){
        cin>>like[i]>>b>>c;
    }
    sort(like,like+n);
    for(int i=0;i<real_n;i++) cnt+=like[i];
    return cnt;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    for(int i=0,n;i<t;i++){
        cin>>n;
        int result=n<=30?solve0(n,n/2):solve1(n,n/2);
        cout<<result<<endl;
    }
    return 0;
}
