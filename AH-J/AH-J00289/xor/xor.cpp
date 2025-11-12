#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
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
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=read(),k=read();
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]==1)cnt2++;
		if(a[i]==0)cnt1++;
	}
	if(k==1){
		cout<<cnt2<<endl;
		return 0;
	}
	if(k==0){
		cout<<cnt1<<endl;
		return 0;
	}
}
