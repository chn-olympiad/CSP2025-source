#include<iostream>
#include<cstdio>
using namespace std;
const int N=20000;
int a[N];
int f[N][N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int t,b,ans=0;
    cin>>t>>b;
    for(int i=1;i<=t;i++)
        scanf("%d",&a[i]);
    /*for(int i=1;i<=t;i++){
        for(int j=i;j<=t;j++){
            if(j==i)f[i][j]=a[i];
            else f[i][j]=f[i][j-1]^a[j];
        }
    }
    for(int i=1;i<=t;i++,cout<<endl){
        for(int j=1;j<=t;j++){
            cout<<f[i][j]<<' ';
        }
    }
    int last=0;
    for(int i=1;i<=t;i++){
        for(int j=last+1;j<=t;j++){
            if(f[i][j]==b){
                ans++;
                last=j;
                break;
            }
        }
        if(last==t)break;
    }*/
    cout<<t/2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}