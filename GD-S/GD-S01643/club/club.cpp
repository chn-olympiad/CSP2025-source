#include<bits/stdc++.h>
#define il inline
#define gc getchar
#define pc putchar
using namespace std;
const int sz=100000;
int t,n,a[sz+5][5];
int p[sz+5],cnt;
char ch;int res;
il int read(){
	res=0,ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch&15),ch=gc();
	return res;
}
void print_(int x){
	if(!x) return;
	print_(x/10);
	pc(x%10+'0');
}
void print(int x){
	if(!x) pc('0');
	else print_(x);
	pc('\n');
}
int cnt1,cnt2,cnt3;
int fl[sz+5],ans;
void solve(){
	n=read(); 
	cnt1=cnt2=cnt3=ans=0;
	for(int i=1;i<=n;i++){
		a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) ++cnt1,fl[i]=1;
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) ++cnt2,fl[i]=2;
		else ++cnt3,fl[i]=3;
	}
	if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
		for(int i=1;i<=n;i++)
			ans+=max(max(a[i][1],a[i][2]),a[i][3]);
		print(ans);
		return;
	}
	cnt=0;
	if(cnt1>n/2){
		for(int i=1;i<=n;i++){
			if(fl[i]==1){
				ans+=a[i][1];
				p[++cnt]=a[i][1]-max(a[i][2],a[i][3]);
			}
			if(fl[i]==2) ans+=a[i][2];
			if(fl[i]==3) ans+=a[i][3];
		}
		sort(p+1,p+cnt+1);
		for(int i=1;i<=cnt1-n/2;i++) ans-=p[i];
		print(ans);
		return;
	}
	if(cnt2>n/2){
		for(int i=1;i<=n;i++){
			if(fl[i]==2){
				ans+=a[i][2];
				p[++cnt]=a[i][2]-max(a[i][1],a[i][3]);
			}
			if(fl[i]==1) ans+=a[i][1];
			if(fl[i]==3) ans+=a[i][3];
		}
		sort(p+1,p+cnt+1);
		for(int i=1;i<=cnt2-n/2;i++) ans-=p[i];
		print(ans);
		return;
	}
	if(cnt3>n/2){
		for(int i=1;i<=n;i++){
			if(fl[i]==3){
				ans+=a[i][3];
				p[++cnt]=a[i][3]-max(a[i][1],a[i][2]);
			}
			if(fl[i]==1) ans+=a[i][1];
			if(fl[i]==2) ans+=a[i][2];
		}
		sort(p+1,p+cnt+1);
		for(int i=1;i<=cnt3-n/2;i++) ans-=p[i];
		print(ans);
		return;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
