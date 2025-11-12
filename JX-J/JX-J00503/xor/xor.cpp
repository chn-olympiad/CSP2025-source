#include<bits/stdc++.h>
using namespace std;
int n,k,a,sum[500005],m=0,u[500005];
struct node{
    int st,ed;
}used[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%i",&a);
        sum[i]=sum[i-1]^a;
    }
    int F=1;
    for(int i=1;i<=n;i++){
        F=0;
        for(int j=i;j<=n;j++){
            if(u[j]!=0) j+=u[j]+i-1;
            if((sum[j]^sum[j-i])==k){
                int f=1;
                for(int l=0;l<m;l++){
                    if(((used[l].st>=j-i+1)&&(used[l].st<=j))||((used[l].ed>=j-i+1)&&(used[l].ed<=j))){
                        f=0;
                        break;
                    }
                }
                if(f){
   //                 cout<<"["<<j-i+1<<","<<j<<"]";
                    u[j-i+1]=i;
                    used[m].st=j-i+1,used[m].ed=j;
                    m++;
                }
            }
        }
    }
    cout<<m;
    return 0;
}
//love wuyin
//a_1 a_2 a_3 a_4 a_5 a_6
//if A ∈ [a_3...a_4],B ∈ [a_1...a_3],C ∈ [a_4...a_6] are OK
//ans_1 ∈ A,ans_1 ∈ C,ans_2 ∈ B
//ans_1 if better than ans_2
//but I can't get ans_1
//right code to slove this problem may be DP
//but mine is qianzhuihe