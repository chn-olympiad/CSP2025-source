#include<cstdio>
#include<iostream>
using namespace std;
bool b[510];
long long m,n,ans,c[510];
string s;
void d(int i,int l){
	if(i==m){
		ans++;
		return;
	}
	if(n-l<m || i+l>=n){
		return;
	}
	for(int j=1;j<=n;j++){
		if(b[j]==0){
			b[j]=1;
			if(l<c[j] && s[i+l]=='1'){
				d(i+1,l);
			}
			else{
				d(i,l+1);
			}
			b[j]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int ss=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			ss++;
		}
	}
	if(ss==n){
		int sss=1;
		for(int i=1;i<=n;i++){
			sss*=i;
		}
		int ssss=1;
		for(int i=1;i<=n-m;i++){
			ssss*=i;
		}
		cout<<sss/ssss;
		return 0;
	}
	if(ss<m){
		cout<<0;
		return 0;
	}
	d(0,0);
	cout<<ans;
	return 0;
} 
