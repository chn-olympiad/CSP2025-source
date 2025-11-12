#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	static int sta[35];
	int top=0;
	do{
		sta[++top]=x%10;
		x/=10;
	}while(x);
	while(top)putchar('0'+sta[top--]);
}
string s;
int cnt[15],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')cnt[s[i]-'0']++;
	}
	for(int i=9;~i;i--){
		while(cnt[i]){
			write(i);
			--cnt[i];
		}
	}
	putchar('\n');
	return 0;
}
/*
难！得！有！几！个！真！兄！弟！
剥蒜的情谊
虽然很久不曾联系
但是放心里惦记~
难！得！有！几！个！真！兄！弟！
走在不同的轨迹~
不必太多的言语
当你需要
我守护你~~~
*/