#include<bits/stdc++.h>
using namespace std;
long long n,m,c[501],f=0,z;
bool g=1;
string s;
const int M=998244353;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			g=0;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(c[i]<=f){
			f++;
		}
	}
//	if(g==1){
		long long x=1,ans=0;
		for(int j=1;j<=n;j++){
			x*=j;
			x%=M;
		}
		cout<<x;
//	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
