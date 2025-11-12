#include<bits/stdc++.h>//30
#define int long long
using namespace std;
void read(int &x){
	x=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
void read(string &str){
	str="";
	char ch=getchar();
	while(ch<'!'||ch>'~')ch=getchar();
	while(ch>='!'&&ch<='~')str+=ch,ch=getchar();
}
void write(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)write(x/10);
	putchar((char)(x%10+'0'));
}
void write(string str){
	for(int i=0;i<str.size();i++)putchar(str[i]);
}
void write(const char ch[]){
	for(int i=0;i<strlen(ch);i++)putchar(ch[i]);
}
template<typename o,typename...c>
void read(o &a,c&...b){
	read(a);
	read(b...);
}
template<typename o,typename...c>
void write(o a,c...b){
	write(a);
	write(b...);
}
int n,m,i,j,ans;string a[200200],b[200200],s1,s2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n,m);
	for(i=1;i<=n;i++)read(a[i],b[i]);
	while(m--){
		read(s1,s2),ans=0;
		if(s1.size()!=s2.size())write("0\n");
		else{
			for(i=0;i<s1.size();i++){
				for(j=1;j<=n;j++){
					if(s1.substr(i,a[j].size())==a[j]&&s1.substr(0,i)+b[j]+s1.substr(i+a[j].size(),s1.size()-i-a[j].size()+1)==s2)ans++;
				}
			}
			write(ans,"\n");
		}
	}
	return 0;
}

