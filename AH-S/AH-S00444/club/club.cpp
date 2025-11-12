#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],b[100005],a0,a1,a2,s;
int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();while(t--){
		s=0;a0=0;a1=0;a2=0;n=read();
		for(int i=1;i<=n;i++){
			a[i][0]=read();a[i][1]=read();a[i][2]=read();
			b[i]=a[i][3]=max(max(a[i][0],a[i][1]),a[i][2]);s+=a[i][3];
			if(a[i][0]==b[i])a0++,b[i]-=max(a[i][1],a[i][2]);
			else if(a[i][1]==b[i])a1++,b[i]-=max(a[i][0],a[i][2]);
			else if(a[i][2]==b[i])a2++,b[i]-=max(a[i][0],a[i][1]);
		}sort(b+1,b+n+1);
		if(a0>n/2)for(int i=1;i<=a0-n/2;i++)s-=b[i];
		if(a1>n/2)for(int i=1;i<=a1-n/2;i++)s-=b[i];
		if(a2>n/2)for(int i=1;i<=a2-n/2;i++)s-=b[i];
		write(s);puts("");
	}
	return 0;
}
