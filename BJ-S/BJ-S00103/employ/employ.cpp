#include<bits/stdc++.h>
using namespace std;
const int N=510;
string s;
int n,m;
int c[N];
int cnta;
int ans;
void fun1(){

}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            cnta++;
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    //specialA
    if(cnta==s.size()){
        ans=1;
        for(int i=n;i>=1;i--){
            ans*=i;
        }
        printf("%d",ans);
        return 0;
    }
    //normal
    fun1();
    return 0;
}
