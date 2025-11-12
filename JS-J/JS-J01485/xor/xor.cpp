#include<bits/stdc++.h>
using namespace std;
long long a[514114];
int er_k[114514];
void er(long long y){
    int i=1;
    while(y!=0){
        er_k[i]=y%2;
        y/=2;
        i++;
    }
    for(int j=1;j<=i/2;j++){
        swap(er_k[j],er_k[i-j]);
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    int b[114514][2];
    cin>>n>>k;
    bool f13=true,f24513=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)f13=false;
        if(a[i]!=1&&a[1]!=0)f24513=false;
    }
    if(f13&&k==0){
        cout<<n/2;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(f24513&&k<=1){
        int num=0;
        if(k==0){
            int num1=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    num++;
                    num1=0;
                }
                else num1++;
                if(num1==2){
                    num++;
                    num1=0;
                }
            }
        }
        if(k==1){
            for(int i=1;i<=n;i++)if(a[i]==1)num++;
        }
        cout<<num;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    long long num;
    er(k);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
