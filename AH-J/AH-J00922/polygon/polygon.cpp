#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long ans;
int a[5005];
bool f;
void dfs(int t,int sum,int q,int cnt,bool f){
    if(sum>2*a[q]&&cnt>=3&&f==1){
        //cout<<cnt<<endl;
        ans++;
        ans%=998244353;
    }
    if(t>n) return ;
    dfs(t+1,sum+a[t],t,cnt+1,1);

    dfs(t+1,sum,q,cnt,0);
}
long long js2(int x){
   long long s1=1,s2=1;
   for(int i=n;i>=n-x+1;i--){
        s1*=i;
   }
   for(int i=x;i>=1;i--){
        s2*=i;
   }
   long long p=s1/s2;
   p%=998244353;
   return p;
}
long long js(){
    long long z=0;
    for(int i=3;i<n;i++){
        z+=js2(i);
        z%=998244353;
    }
    z++;
    z%=998244353;
    return z;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) f=1;
    }
    if(f){
        sort(a+1,a+n+1);
        dfs(1,0,0,0,0);
        cout<<ans;
    }else{
       cout<<js();
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//1042392
//#Shang4Shan3Ruo6Shui4
