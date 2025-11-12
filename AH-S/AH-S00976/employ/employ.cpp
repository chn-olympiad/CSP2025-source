#include<bits/stdc++.h>
using namespace std;
const int N=510,MOD=998244353;
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
int cf(int x){
	int an=1;
	while(x--){
		an*=2;
		an%=MOD;
	}
	return an;
}
int n,m,a[N],t[N];
bool ta=false,tb=false;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++) t[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(t[i]==0) ta=true;
		else tb=true;
	}
	if(!tb||(ta&&m==n)){
		cout<<'0'<<endl;
	}else if(!ta||(tb&&m==1)){
		cout<<cf(n)%MOD<<endl;
	}
	return 0;
}
