#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define int long long
#define ps puts("")
#define pc putchar(' ')
#define f(i,l,r) for(i=l;i<=r;++i)
int t,n,ans,cn[4],mxn,mxi;
struct nd{
	int b[4],mx,j,mn,y;
}a[N];
int read(){
	int res=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void write(int x){
	static int st[40],top=0;
	if(x<0){
		putchar('-');
		x=-x;
	}
	while(x) st[++top]=x%10,x/=10;
	if(!top) st[++top]=0;
	while(top) putchar(st[top--]^48);
	return ;
}
bool cmp(nd i,nd j){
	if(i.y==j.y) return i.mn<j.mn;
	return i.y>j.y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j;
	t=read();
	while(t--){//Çå¿Õ
		n=read();
		mxn=mxi=ans=cn[0]=cn[1]=cn[2]=cn[3]=0;
	 	f(i,1,n){
		 	f(j,1,3) a[i].b[j]=read();
		 	a[i].mx=a[i].mn=a[i].j=a[i].y=0;
		 	f(j,1,3){
		 		if(a[i].b[j]>a[i].mx){
		 			a[i].mx=a[i].b[j];
		 			a[i].j=j;
	 				a[i].mn=min(a[i].mx-a[i].b[(j+1-1+3)%3+1],a[i].mx-a[i].b[(j-1-1+3)%3+1]);
				}
//	 			cout<<j<<" "<<(j+1-1+3)%3+1<<" "<<(j-1-1+3)%3+1<<endl;
			}
			++cn[a[i].j];
			ans+=a[i].mx;
			if(cn[a[i].j]>mxn){
				mxn=cn[a[i].j];
				mxi=a[i].j;
			}
		 }
		f(i,1,n) a[i].y=a[i].j==mxi;
		if(mxn>n/2){
			sort(a+1,a+n+1,cmp);
			for(i=1;mxn>n/2;++i){
				ans-=a[i].mn;
				--mxn;
			}
		}
		write(ans);ps;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
