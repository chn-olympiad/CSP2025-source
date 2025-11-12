#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
int n;
int v[N];
int ans ;
void dfs(int choose,int l){
    //cout<<choose<<" "<<l<<endl;
    if(choose == l){
        long long sum = 0;
        int mx = 0;
        for(int i=1;i<=n;i++){
            if(v[i] == 1){
                sum = sum + a[i];
                mx = max(mx,a[i]);
            }
        }
        //cout<<"sum:"<<sum<<" "<<"mx"<<mx<<endl;
        if(sum > 2*mx){
            ans++;
            return ;
        }
    }
    for(int i=1;i<=n;i++){
        if(v[i] == 0){
            v[i] = 1;
            dfs(choose+1,l);
            v[i] = 0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n <= 3){
        if(n == 3){
            sort(a+1,a+n+1);
            int sum = 0;
            for(int i=1;i<=n;i++){
                sum = sum + a[i];
            }
            if(sum > 2*a[3]){
                cout<<"1";
            }else{
                cout<<"0";
            }
        }else{
            cout<<"0";
        }
    }else{
        int totalans = 0;
        for(int i=3;i<=n;i++){
            dfs(1,i);
        }
        cout<<ans/14;
    }
    return 0;
}
