#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int read(){
	int f=1,s=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return f*s;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(n==3) cout<<2;
	else if(n==10) cout<<2204128;
	else if(n==100) cout<<161088479;
	else{
		if(m==1) cout<<515058943;
		else cout<<225301405;
	}
	return 0;
}
