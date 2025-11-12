#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int &x){
	char ch=0;
	bool flag=false;
	x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-') flag=true;
		ch=getchar();
	}
	if(flag)
	while(ch>='0'&&ch<='9')
	x=x*10-(ch-'0'),ch=getchar();
	else
	while(ch>='0'&&ch<='9')
	x=x*10+(ch-'0'),ch=getchar();
}
inline void write(int x){
	bool flag=false;
	if(x<0) flag=true;
	if(flag) putchar('-');
	static int sta[40];
	int top=0;
	do{
		sta[top++]=x%10;
		x/=10;
	}while(x);
	if(flag)
	while(top) putchar('0'-sta[--top]);
	else
	while(top) putchar('0'+sta[--top]);
}
string s;
int a[15]; 
signed main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	if(s[i]>='0'&&s[i]<='9')
	a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
	for(int j=1;j<=a[i];j++)
	putchar(i+'0');
	return 0;
}
//don`t let this show in luogu,because my classmate will see it
//CCF sm
//zyt,I like you
//zyt is a guangdong foshan nanhai Dali Middle School student,me too.
//zyt is Class 22  Grade 8 No.37,I`m Class 22 Grade 8 No.36
