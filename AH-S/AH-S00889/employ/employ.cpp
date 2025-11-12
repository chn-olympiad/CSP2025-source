#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long n,m,b[N],f,s[N],x[N],cnt,y[N];
char a[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]=='0')
			f=1;
	}
	s[0]=1;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		s[i]=s[i-1]*i%998244353;
		if(b[i]==0)
			f=1;
		x[b[i]]++;
	}
	y[0]=n-x[0];
	for(int i=1;i<=n;i++)
		y[i]=y[i-1]-x[i];
	if(m==n){
		if(f==1) cout<<0;
		else cout<<s[n];
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]=='0') cnt++;
			else{
				cnt+=y[cnt]*s[n-1]%998244353;
				cnt%=998244353;
			}
		}
		cout<<cnt;
	}
	else if(f==0)
		cout<<s[n];
	else
		cout<<0;
    return 0;
}
