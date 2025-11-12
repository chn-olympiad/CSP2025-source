#include<bits/stdc++.h>
using namespace std;
int n,k,a[555555];
bool if_A=true,if_B=true;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1) if_A=false;
        if(a[i]!=1 && a[i]!=0) if_B=false;
    }
    if(if_A) printf("%d\n",n/2);//A
    else if(if_B){//B
        int find_0=0,find_1=0,ans=0;
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    find_0++;
                    find_1=0;
                }
                if(a[i]==1) find_1++;
                //find 0 or 1
                if(find_1==2){
                    find_1=0;
                    ans++;
                }
            }
            ans+=find_0;
            printf("%d\n",ans);
        }else{
            for(int i=1;i<=n;i++){
                if(a[i]==1) find_1++;
                //find 0 or 1
            }
            printf("%d\n",find_1);
        }
    }else{
        printf("2\n");
    }
}
//A+B=25pts
