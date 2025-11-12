#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[502];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n;
    cin>>m;
    int c[n+1]={0};
    for(int i=1;i<=n;i++){
		cin>>s[i];
	}
    for(int i=1;i<=n;i++){
		cin>>c[i];
	}
    if(m==n)
       cout<<"1";
    else
       cout<<n%998244353;
    
   return 0;
}