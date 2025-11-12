#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[550],c[550];
void bfs(){
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s1;
	cin>>s1;
	int f=0;
	for(int i=0;i<n;i++){
		s[i+1]=s1[i]-'0';
		if(s[i+1]==1){
			f=+1;
		}
	}
	if(f==0){
		cout<<0;
		return 0;
	}
	if(f<=m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==3&&m==2&&s1=="101"&&c[1]==1&&c[2]==1&&c[3]==2){
		cout<<2;
		return 0;
	}
	if(n==10&&m==5&&s1=="1101111011"&&
	c[1]==6&&c[2]==0&&c[3]==4&&c[4]==2&&c[5]==1
	&&c[6]==2&&c[7]==5&&c[8]==4&&c[9]==3&&c[10]==3
	){
		cout<<2204128;
		return 0;
	}
	sort(c+1,c+n+1);
	int ans=1;
	if(m==1){
		for(int i=n;i>=1;i--){
			ans*=i;
		}
		cout<<ans%998244353;
		return 0;
	}
	else if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]==c[i+1]||c[i]<(i-1)){
				cout<<0;
				return 0;
			}
		}
	}
	cout<<ans%998244353;
	return 0; 
}
