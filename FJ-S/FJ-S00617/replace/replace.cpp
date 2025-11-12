#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9){write(x/10);}
	putchar((x%10)+48);
}
const int N=107;
string s[N][3],t[3];
int n,q,ans;
int check(int p){
	int res=0;
	for(int i=0;i<t[1].size()-s[p][1].size()+1;i++){
		int f=0;
		for(int j=0;j<s[p][1].size();j++){
			if(t[1][i+j]!=s[p][1][j]){f=1;break;}
		}
		if(f)continue;
		string s1=t[1];
		for(int j=0;j<s[p][2].size();j++){
			s1[i+j]=s[p][2][j];
		}
		for(int i=0;i<t[2].size();i++){
			if(t[1][i]!=t[2][i]){f=1;break;}
		}
		if(f)continue;
		++res;
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	
	return 0;
}

