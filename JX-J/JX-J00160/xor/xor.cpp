#include<bits/stdc++.h>
using namespace std;
long long int linshi,a[21],b[21],c[21],d[21],res,res2,n,k,k2,sg[500001],sum;
bool flag=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out',"w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> sg[i];
    for(int i=1;i<=n;i++){
        if(sg[i]==k){
            sum++;
            continue;
        }else{
            linshi=sg[i];
            res=0;
            while(linshi!=0){
                res++;
                d[res]=linshi%2;
                linshi/=2;
            }
            if(flag==1){
                for(int j=1;j<=res;j++){
                    a[j]=d[j];
                }
            }else{
                for(int j=1;j<=res;j++){
                    b[j]=d[j];
                }
                res2=res;
                while(a[res2]==0){
                    res2++;
                }
                res2-=1;
                for(int j=1;j<=res2;j++){
                    if(a[j]==b[j]) c[j]=0;
                    if(a[j]!=b[j]) c[j]=1;
                }
                int linshi2=1;
                for(int j=1;j<=res2;j++){
                    if(c[j]==1) k2+=linshi2;
                    linshi2*=2;
                }
                if(k2==k){
                    sum++;
                }else{
                    for(int j=1;j<=res2;j++){
                        a[j]=c[j];
                    }
                }
            }
        }
        cout << sum;
    }
    return 0;
}
