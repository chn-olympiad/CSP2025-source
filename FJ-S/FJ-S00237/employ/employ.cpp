#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],b[505],flag=1,a[505],tot,ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];	
		if(c[i]!=0){
			tot++;
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=s[i-1]-'0';
		if(b[i]!=1){
			flag=0;
		}
	}
	if(flag==1){
		memset(a,tot,sizeof(a));
		for(int i=1;i<=n;i++){
			if(c[i]!=0&&c[i]<=n){
				for(int j=1;j<=a[i];j++){
					a[j]--;
				}
			}
		}
		for(int i=1;i<=m;i++){
			ans=ans*a[i]%998244353;
		}
		cout<<ans;	
	}else{
		int aa=0;
		if(m==1&&b[1]==1){
			cout<<tot;
		}else if(m==1&&b[1]==0){
			for(int i=1;i<=n;i++){
				if(b[i]==1){
					aa++;
				}
			}
			cout<<tot-aa;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
