#include<bits/stdc++.h>
using namespace std;
#define in(s1) freopen(s1,"r",stdin);
#define out(s1) freopen(s1,"w",stdout);
#define pii pair<int,int>
template<typename T>
inline void read(T &x){
	x=0;
	char c=getchar();
	int f=1;
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+(c-'0');
		c=getchar();
	}
	x*=f;
}
template<typename T>
inline void write(T x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
string s;
int k[20];
int main(){
	in("number.in")
	out("number.out")
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')k[s[i]-'0']++;
	bool f=1;
	for(int i=1;i<=9;i++){
		if(k[i]){
			f=0;
			break;
		}
	}
	if(f){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--)for(int j=1;j<=k[i];j++)cout<<i;
	return 0;
}
