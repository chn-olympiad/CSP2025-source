#include<bits/stdc++.h>
#define int long long
using namespace std;
struct _queue{
	int a[1000005],head=1,tail;
	int _front(){return a[head];}
	bool _empty(){return tail<head;}
	void _push(int x){a[++tail]=x;}
	void _pop(){head++;}
};
struct _stack{
	int a[1000005],head;
	int _top(){return a[head];}
	bool _empty(){return head;}
	void _push(int x){a[++head]=x;}
	void _pop(){head--;}
};
inline int read(){
	int x=0,f=1;
	char c=getchar(); 
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
const int N=1e5+5;
int n,T,a[N][3],ans;
int x1[N],len1,x2[N],len2,x3[N],len3; 
void init(){
	len1=len2=len3=ans=0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		init();
		n=read();
		for(int i=1;i<=n;i++){
			a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				x1[++len1]=max(a[i][1],a[i][2])-a[i][0];
				ans+=a[i][0];
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				x2[++len2]=max(a[i][0],a[i][2])-a[i][1];
				ans+=a[i][1];
			}
			else {
				x3[++len3]=max(a[i][0],a[i][1])-a[i][2];
				ans+=a[i][2];
			}
		}
		if(len1>n/2){
			sort(x1+1,x1+len1+1);
			for(int i=n/2+1;i<=len1;i++) ans+=x1[i];
		}
		else if(len2>n/2){
			sort(x2+1,x2+len2+1);
			for(int i=n/2+1;i<=len2;i++) ans+=x2[i];
		}
		else if(len3>n/2){
			sort(x3+1,x3+len3+1);
			for(int i=n/2+1;i<=len3;i++) ans+=x3[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}


