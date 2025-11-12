//remember:ctrl+s!!!
//ctrl+s!!!
//ctrl+s!!!
//baocun!!!
//xiugai name!!!
//name!=1,2,3,4!!!
#include<bits/stdc++.h>
using namespace std;
int n,mg[5005]={0};long long ans=0;
void dfs(long long sum,int m,int maxn,int sl){//maxn:muqianzuidashu's xiabiao
    if(sum>mg[maxn]*2&&sl>=3){
        ans++;
        cout<<sum<<" "<<maxn<<endl;
    }   
    if(m>=maxn) return ;//bianjie

    dfs(sum+mg[m],m+1,maxn,sl+1);//na
    dfs(sum,m+1,maxn,sl);//buna
}

int main(){
    //ctrl+s!!!
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    //quxiaozhushi:yiding     ctrl+s!!!

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n; 
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin>>mg[i];
        sum+=mg[i];
    }
    sort(mg+1,mg+n+1);
    

    for(int i=3;i<=n;i++){
        dfs(mg[i],1,i,1);
        
    }
    cout<<ans%998244353;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
//  g++ 1.cpp -o 1 -std=c++14