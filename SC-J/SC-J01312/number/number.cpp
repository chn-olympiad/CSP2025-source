#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read(){
	int ans=0,j=1;
	char c=getchar();
	while(c>'9' or c<'0'){
		if(c=='-')
			j=-1;
		c=getchar();
	}
	while(c>='0' and c<='9'){
		ans=(ans<<1)+(ans<<3)+(c^48);
		c=getchar();
	}
	return ans*j;
}
void write(ll x){
	if(x<0)
		putchar('-'),
		x=-x;
	if(x>9)
		write(x/10);
	putchar('0'+x%10);
}
int tot;
string s;
char c[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i)
		if(s[i]>='0' and s[i]<='9')
			c[++tot]=s[i];
	sort(c+1,c+tot+1);
	for(int i=tot;i>=1;--i)
		putchar(c[i]);
	return 0;
}
/*
这道题太水了
都不用对拍
我直接3min切掉
过不了我吃

此题每挂1分，我围着操场跑10圈


CSP-J有感 - QMR

马鞍山上游，
格致楼中站。
抬眼远望，
晴空茫茫云飘散。

昨晚月皎洁，
今朝日照辉，
追忆朝夕，
青春灿灿人无悔。
*/