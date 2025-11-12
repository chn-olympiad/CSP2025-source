#include<bits/stdc++.h>
using namespace std;
int read(){
	char ch=getchar();
	int x=0;
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
struct node{
	int val,nval;
}a[100005],b[100005],c[100005];
bool cmp(node a,node b){
	return a.nval>b.nval;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	t=read();
	while(t--){
		int ans=0;
		int n;
		n=read();
		int acnt=0,bcnt=0,ccnt=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			x=read(),y=read(),z=read();
			ans+=max(x,max(y,z));
			if(x>=y&&x>=z){
				a[++acnt].val=x;
				if(y>z)a[acnt].nval=y-x;
				else a[acnt].nval=z-x;
			}
			else if(y>=x&&y>=z){
				b[++bcnt].val=y;
				if(x>z)b[bcnt].nval=x-y;
				else b[bcnt].nval=z-y;
			}
			else if(z>=y&&z>=x){
				c[++ccnt].val=z;
				if(y>x)c[ccnt].nval=y-z;
				else c[ccnt].nval=x-z;
			}
		}
		if(acnt>n/2){
			sort(a+1,a+acnt+1,cmp);
			for(int i=1;i<=acnt-n/2;i++){
				ans+=a[i].nval;
			}
		}
		else if(bcnt>n/2){
			sort(b+1,b+bcnt+1,cmp);
			for(int i=1;i<=bcnt-n/2;i++){
				ans+=b[i].nval;
			}
		}
		else if(ccnt>n/2){
			sort(c+1,c+ccnt+1,cmp);
			for(int i=1;i<=ccnt-n/2;i++){
				ans+=c[i].nval;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}