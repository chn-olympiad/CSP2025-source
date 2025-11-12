#include"algorithm"
#include"iostream"
#include"vector"
#include"cmath"
#define men 998244353
int n;
std::vector<int> v(n+5);
int res(int num){
    int ans=0;
    bool b[n+5]={false};
    for(int i=1;i<=num;i++){
        for(int j=2;j<=num;j++){
            for(int q=3;q<=num;q++){
                if((v[i]+v[j]+v[q]>v[q]*2)&&((!b[i])||(!b[j])||(!b[q]))){
                    ans++;
                    b[i]=true;
                    b[j]=true;
                    b[q]=true;
                }
            }
        }
    }
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::cin>>v[i];
    }
    std::sort(v.begin(),v.end());
    int ans=0;
    for(int m=3;m<=n;m++){
        ans+=res(m);
        ans%=men;
    }
    std::cout<<ans;
    return 0;
}
