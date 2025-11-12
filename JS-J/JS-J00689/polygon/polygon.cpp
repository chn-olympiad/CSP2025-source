#include<bits/stdc++.h>
using namespace std;
int a[3005];
int great[3005];
int n;
int fun1(int deep,int maxn_add,int b){
    if(deep==0){
        long long num=0;
        for(int i=1;i<=b;i++){
            num+=a[great[i]];
        }
        if(num>2*a[great[b]]){
            return 1;
        } 
        else return 0;
    }
    long long num=0;
    for(int i=great[b-deep-1]+1;i<=maxn_add-deep;i++){
        great[b-deep]=i;
        num+=fun1(deep-1,maxn_add,b);
    }
    return num%998244353;
} 
int cnt[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    } 
    int flag_num=1;
    for(int i=1;i<=5000;i++){
        if(cnt[i]>0){
            for(int j=0;j<cnt[i];j++){
                a[flag_num]=i;
                flag_num++;
            }
        }
    }
    long long num=0;
    for(int i=3;i<=n;i++){
        for(int j=i;j<=n;j++){
            great[i]=j;
            num+=fun1(i-1,j,i);
        }
            
            
    }
    cout<<num%98244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
