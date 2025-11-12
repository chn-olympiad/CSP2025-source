#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],b[505],ans,ma; 
string s;
long long lk=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	bool flag=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) flag=1;
		b[i]=i;
		ma=max(ma,a[i]);
	}
	if(!flag){
		if(m==n){
			for(int i=2;i<=n;i++){
				lk*=i;
				lk%=998244353;
			}
			cout<<lk;
		}
		else cout<<0;
		return 0;
	} 
	do{
		int ss=0,h=0;
		for(int i=1;i<=n;i++){
			if(a[b[i]]>h&&s[i-1]=='1') ss++;
			else if(s[i-1]=='0') h++;
			if(h>=ma) break;
		}
		if(ss>=m) ans=(ans+1)%998244353;
	}while(next_permutation(b+1,b+1+n));
	cout<<ans;
}
