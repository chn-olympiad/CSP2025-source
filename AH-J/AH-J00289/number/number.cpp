#include<bits/stdc++.h>
const int N = 1e6 + 10;
int a[N];
using namespace std;
int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main(){
	//5201314312699
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	int j=0;
	for(int i=0;i<l;i++){
		if(isdigit(s[i]))j++,a[j]=s[i]-'0';
	}
	sort(a+1,a+j+1);
	for(int i=j;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
