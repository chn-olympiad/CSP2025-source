//GZ-S00448 ËçÑôÖÐÑ§ ½ð¿¡Î°
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring> 
using namespace std;
int main()
{
	fro("employ.in","r",stdin);
	fro("employ.out","w",stdout);
	int n,m; scanf("%d%d",&n,&m);
	string s; 
	cin>>s;
	int c[501];
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(n<=18){
		int a[20];
		for(int i=1;i<=n;i++) a[i]=i;
		unsigned long long ans=0;
		do{
			int cnt=0,fal=0;
			for(int i=1;i<=n;i++){
				if(fal>=c[a[i]]){
					fal++;
					continue;
				} 
				else if(s[i-1]=='1') cnt++;
				else fal++;
				if(cnt==m){
					ans++;
					break;
				} 
			}
		}while(next_permutation(a+1,a+n+1));
		cout<<ans%998244353;
	}
	else if(m==1){
		sort(c+1,c+n+1);
	}
	else if(m==n){
		int flag=0;
		for(int i=0;i<n;i++) if(s[i]=='0') flag=1;
		sort(c+1,c+n+1);
		if((flag==1)||(c[1]==0)) cout<<0;
		else{
			unsigned long long ans=1;
			for(int i=0;i<n;i++) ans=ans*(n-i);
			cout<<ans%998244353;
		}
	}
	else{
		
	}
	return 0;
}
