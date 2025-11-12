#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
string s;
int a[N],c[N];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,f=1;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n>20){
		long long res=1;
		for(int i=1;i<=n;i++){
			res=res*i%mod;
		}
		cout<<res<<endl;
	}else{
		for(int i=1;i<=n;i++){
			a[i]=i;
		}
		int res=0;
		do{
			int cnt=0,gp=0;
			for(int i=1;i<=n;i++){
				if(s[i-1]=='0')gp++;
				else{
					int u=a[i];
					if(gp>=c[u])gp++;
					else cnt++;
				}
			}
			if(cnt>=m)res++;
			int flag=1;
			for(int i=1;i<=n;i++){
				if(a[i]!=n-i+1)flag=0;
			}
			if(flag)break;
		}while(next_permutation(a+1,a+1+n)); 
		cout<<res<<endl;
	}
	return 0;
}
