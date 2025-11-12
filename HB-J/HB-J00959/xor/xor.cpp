#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int zl;
int jl[500005];//ji lu  yihuo zhi
bool bx(int cmp_j,int cmp_i){
    int cmp=a[cmp_j];
    for(int x=cmp_j+1;x-cmp_j<cmp_i;x++){
        if(a[x]!=-1)
            cmp=cmp xor a[x];
        else
            return false;
    }
    if(cmp==k){
        return true;
    }else{
        return false;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    int cmp_a;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        jl[i]=a[i];
        if(a[i]==k){
            a[i]=-1;
            jl[i]=-1;
            zl++;
        }
    }
    /*for(int cmp=1;cmp<=n;cmp++){
            cout<<a[cmp]<<"  ";
        }
    cout<<endl;*/
    /*for(int i=2;i<=n;i++){
        for(int cmp=1;cmp<=n;cmp++){
            cout<<a[cmp]<<"  ";
        }
        cout<<endl;
        for(int j=1;j<=n-i+1;j++){
            if(bx(j,i)){
                zl++;
                for(int cmp=j;cmp-j<i;cmp++){
                    a[cmp]=-1;
                }
            }
        }
    }*/
    /*for(int j=1;j<=n-1;j++){
        jl[j]=a[j] xor a[j+1];
        if(jl[j]==k){
            zl++;
            //ru guo deng yu k, na me jiu ba mei ge liang de qian j-i+1 wei dao j+2-1 bian wei -1
            for(int i=j-2+1;i<=j+2-1;i++){
                jl[j]=-1;
            }
        }
    }*/
    /*for(int cmp=1;cmp<=n-2+1;cmp++){
            cout<<jl[cmp]<<"  ";
        }
    cout<<endl;*/
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            if(jl[j]>=0){
                jl[j]=jl[j] xor a[j+i-1];
                if(jl[j]==k){
                    zl++;
                    //ru guo deng yu k, na me jiu ba mei ge liang de qian j-i+1 wei dao j+2-1 bian wei -1
                    for(int d=j-i+1;d<=j+i-1;d++){
                        jl[d]=-1;
                    }
                    for(int d=j;d-j<=i-1;d++){
                        a[d]=-1;
                    }
                }
            }
        }
        /*for(int cmp=1;cmp<=n-i+1;cmp++){
            cout<<jl[cmp]<<"  ";
        }
        cout<<endl;*/
    }
    cout<<zl;
    return 0;
}


