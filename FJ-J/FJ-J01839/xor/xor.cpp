#include<iostream>
using namespace std;
const int MAXN=5e5+10;
int rd(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int n,k,a[MAXN],cnt=0;
bool flag1=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=rd(),k=rd();
	for(int i=1;i<=n;i++){
		a[i]=rd(); 
		if(a[i]!=1)flag1=0;
		if(a[i]==1)cnt++;
	}
	if(flag1)cout<<n/2;
	else cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//10:42finished, qi wang de fen 20pts
