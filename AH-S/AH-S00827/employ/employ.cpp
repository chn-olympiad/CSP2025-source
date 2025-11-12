#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long mod=998244353ll;
int n,m,c[505],cnt,sum,t;
int a[15]={0,1,2,3,4,5,6,7,8,9,10};
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=0;i<n;i++) cin>>c[i];
    if(n<=10){
        do{
            sum=cnt=0;
            for(int i=0;i<n;i++){
                if(c[a[i]]<=cnt) cnt++;
                else if(s[i]=='0') cnt++;
                else sum++;
            }
            if(sum>=m) t++;
        }while(next_permutation(a,a+n));
        cout<<t;
    }else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


