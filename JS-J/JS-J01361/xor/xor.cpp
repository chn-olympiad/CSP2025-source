#include<bits/stdc++.h>
using namespace std;
int a[500002],prefix[500002];
int sum(int left,int right){
    return prefix[right]^prefix[left]^a[left];
}
int n,k;
bool solve(int left,int right,int cnt){
    //printf("in solve(%d,%d,%d)\n",left,right,cnt);
    if(cnt==0){
     //   printf("true\n");
        return true;
    }
    if(right<left||right-left+1<cnt){
      //  printf("false\n");
        return false;
    }

    if(right-left+1==cnt){
        for(int i=1;i<=n;i++)
            if(a[i]!=k){
               // printf("false\n");
                return false;
            }
       // printf("true\n");
        return true;
    }
    for(int l=left;l<=right;l++)
        for(int r=l;r<=right;r++){
           // printf("sum(%d,%d)=%d\n",l,r,sum(l,r));
            if(sum(l,r)==k){
               // printf("pass\n");
                if(cnt==1){
                    //printf("true\n");
                    return true;
                }
                for(int i=0;i<=cnt-1;i++){
                    //printf("solve(%d,%d,%d)&&solve(%d,%d,%d)\n",left,l-1,i,r+1,right,cnt-1-i);
                    if(solve(left,l-1,i)&&solve(r+1,right,cnt-1-i)){
                        //printf("true\n");
                        return true;
                    }
                }
            }
        }
   // printf("false\n");
    return false;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        prefix[i]=prefix[i-1]^a[i];
    }
    for(int i=n;i>=0;i--){
        if(solve(1,n,i)){
            cout<<i;
            return 0;
        }
    }
    return 0;
}
