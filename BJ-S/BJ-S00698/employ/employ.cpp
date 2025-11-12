#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m;
int nx[505];
string s[505];
int main(){
    //freopen("employ.in","r",stdin);
    //freopen("employ.out","w",stdout);
    cin>>n>>m;
    long long t=n,x=1,k=0;
    for(int i=1;i<=n;i++){
		char c;
		cin>>c;
        if(c=='0') k++;
        s[i]=c;
    }
    if(m==1){
		for(int i=1;i<=n;i++){
			cin>>nx[i];
			if(nx[i]<m) t=t-1;
			else t=t;
		}
        cout<<t;
        return 0;
    }
    else
    for(int i=1;i<=n;i++){
        cin>>nx[i];
        if(nx[i]==0) t=t-1;
        else t=t;
    }
    for(int i=t;i>=t-m;i--){
        x=x*i%N;
    }
    cout<<x%N;
}
