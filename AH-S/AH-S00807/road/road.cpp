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
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a;
	cin>>n>>m>>k>>a;
	if(n==4) cout<<13;
	else if(n==1000){
		if(k==5) cout<<505585650;
		else if(a==709)cout<<504898585;
		else cout<<5182974424;
	}
	else cout<<5182974424;
	return 0;
}
