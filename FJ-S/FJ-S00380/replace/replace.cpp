#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,q;
string s1[N],s2[N],t1,t2;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void print(int x){
	if(x>9){
		print(x/10);
	}
	putchar(x%10+'0');
	return ;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
	}
	return 0;
}
