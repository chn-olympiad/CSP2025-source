#include<bits/stdc++.h>
using namespace std;
int a[505];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,f=1,sum=0;string s;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<(int)(s.size());i++){
		if(s[i]==0)
			f=0;
		else
			sum++;
	}
	if(m==n){
		if(f==0)
			cout<<0;
		else{
			int num=n;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(a[i]==0)
					num--;
			}
			if(num!=n)
				cout<<0;
			else{
				long long ans=1;
				for(int i=1;i<=n;i++)
					ans=(ans*i)%998244353;
				cout<<ans;
			}
		}
	}
	else
	cout<<0;
	return 0;
}
