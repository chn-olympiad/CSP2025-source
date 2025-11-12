#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace FastIO{
	template<class T>
	T read(T&x){
		x=0;bool f=false;char ch=getchar();
		while(!isdigit(ch)) f|=!(ch^'-'),ch=getchar();
		while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch&0xF),ch=getchar();
		x=(f?-x:x);return x;
	}template<class T>
	void write(T x,char ch=' '){
		if(x<0) putchar('-'),x=-x;
		char tmp[41];int cnt=0;
		while(x>9) tmp[cnt++]=x%10+'0',x/=10;tmp[cnt++]=x+'0';
		while(cnt) putchar(tmp[--cnt]);putchar(ch);
	}
};
using namespace FastIO;
const int N=1e5+10;
struct node{int x,y,z,val;}a[N],A[N],B[N],C[N];
int cnt1,cnt2,cnt3,n,T;
ll ans;
inline bool cmp(node x,node y){return x.val<y.val;}
void work(){
	read(n);
	cnt1=cnt2=cnt3=ans=0;
	for(int i=1;i<=n;i++){
		read(a[i].x),read(a[i].y),read(a[i].z);
		int maxn=max({a[i].x,a[i].y,a[i].z});
		if(maxn==a[i].x) a[i].val=max(a[i].y,a[i].z)-a[i].x,A[++cnt1]=a[i];
		else if(maxn==a[i].y) a[i].val=max(a[i].x,a[i].z)-a[i].y,B[++cnt2]=a[i];
		else a[i].val=max(a[i].x,a[i].y)-a[i].z,C[++cnt3]=a[i];
		ans+=maxn;
	}
	if(cnt1>n/2){
		sort(A+1,A+cnt1+1,cmp);
		for(int i=n/2+1;i<=cnt1;i++) ans+=A[i].val;
	}
	if(cnt2>n/2){
		sort(B+1,B+cnt2+1,cmp);
		for(int i=n/2+1;i<=cnt2;i++) ans+=B[i].val;
	}
	if(cnt3>n/2){
		sort(C+1,C+cnt3+1,cmp);
		for(int i=n/2+1;i<=cnt3;i++) ans+=C[i].val;
	}
	write(ans,'\n');
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>T;
	while(T--) work();
	fclose(stdin);fclose(stdout);
	return 0;
}
