#include<bits/stdc++.h>
using namespace std;
long long read();
void write(long long a);
long long n,k,a[500005],ans,lr=0,now,ma=-10;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	//for(int i=1;i<=n;i++) cout<<a[i]<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j==i) now=a[j];
			else now=now^a[j];
			//cout<<now<<endl;
			if(now==k){
				//cout<<i<<" "<<j<<endl;
				if(lr<i){
					ans++;
					lr=j;
				}
				else if(lr>j) lr=j;
				break;
			}
		}
	}
	write(ans);
	return 0;
}
long long read(){
	long long f=1,now=0;
	char c;
	c=getchar();
	while('0'>c||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		now=(now<<3)+(now<<1)+c-'0';
		c=getchar();
	}
	return now*f;
}
void write(long long a){
	if(a<0){
		putchar('-');
		a=-a;
	}
	if(a>=10) write(a/10);
	putchar(a%10+'0');
}
