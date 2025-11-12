#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int a,b;
    scanf("%d%d",&a,&b);
    string s;
    cin>>s;
    long long ans=1;
    for(int i=1;i<=b;i++){
        ans=ans*a%N;
        a--;
    }
    cout<<ans;
    return 0;
}
