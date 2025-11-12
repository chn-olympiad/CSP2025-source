#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int tot, len, qlen, a[N];
int read(){
	int s=0, f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0) x=-x, putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
bool cmp(int a, int b){return a>b;}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int p=0;
	while(1){
		char ch=getchar();
		if(ch=='\n') break;
		else if(isdigit(ch)) p++, a[p]=ch-'0';
	}
	sort(a+1, a+p+1, cmp);
	for(int i=1; i<=p; i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
