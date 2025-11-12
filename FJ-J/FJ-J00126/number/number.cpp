#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+50;
int a[N],cnt;
string s;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48),ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x<10){putchar(x+48);}
	else{write(x/10);putchar(x%10+48);}
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=(s[i]-48);
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--)putchar(a[i]+'0');
	fclose(stdin);
	fclose(stdout);
	return 0;
}
