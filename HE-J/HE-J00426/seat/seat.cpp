#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b; 
}
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n*m;i++){
			a[i]=read();
	}
	int l=a[1],l1=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==l){
			l1=i;
			break;
		}
	}
	int lie=l1/n+1,zong=l1%(2*n),hang=0;
	if(l1%n==0)lie--;
	if(l1%(2*n)==0)zong=2*n;
	if(zong<=n)hang=zong;
	else hang=2*n-zong+1;
	cout<<lie<<' '<<hang<<endl;
	return 0;
}

