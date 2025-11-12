#include<bits/stdc++.h>
using namespace std;
long long read(){
	 long long a=0;
	 short b=1;
	 char c=getchar();
	 while(c<'0'||c>'9'){
	 	if(c=='-') b=-1;
	 	c=getchar();
	 }
	 while(c>='0'&&c<='9'){
		 a=(a<<3)+(a<<1)+c-48;
		 c=getchar();
	 }
	 return a*b;
}
int ac[1100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=read(),k=read(),ans=0,x,r=0;
	for(int i=1;i<=1048576;i++) ac[i]=-1;
	for(int i=1;i<=n;i++){
		int a=read();
		if(i==1) x=a;
		else x=x^a;
		if(ac[x^k]>=r){
			ans++;
			r=i;
		}
		ac[x]=i;
	}
	cout <<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}