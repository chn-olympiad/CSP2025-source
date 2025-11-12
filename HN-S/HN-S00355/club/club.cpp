#include<bits/stdc++.h>
using namespace std;
#define N 100010
int n,T,t[4],x[4],w1[N],w2[N],w3[N];
struct node{
	int club,m;
}a[N];
int read(){
	int res=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		int ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				x[j]=read();
				if(x[j]>a[i].m){
					a[i].m=x[j];
					a[i].club=j;
				}
			}
			t[a[i].club]++;
			if(a[i].club==1) w1[t[a[i].club]]=min(abs(x[1]-x[2]),abs(x[1]-x[3]));
			if(a[i].club==2) w2[t[a[i].club]]=min(abs(x[1]-x[2]),abs(x[2]-x[3]));
			if(a[i].club==3) w3[t[a[i].club]]=min(abs(x[3]-x[2]),abs(x[1]-x[3]));
			ans+=a[i].m;
		}
		if(t[1]>n/2){
			int q=t[1];
			sort(w1+1,w1+q+1);
			for(int i=1;i<=q;i++){
				ans-=w1[i];
				t[1]--;
				if(t[1]==n/2) break;
			}
		}
		if(t[2]>n/2){
			int q=t[2];
			sort(w2+1,w2+q+1);
			for(int i=1;i<=q;i++){
				ans-=w2[i];
				t[2]--;
				if(t[2]==n/2) break;
			}
		}
		if(t[3]>n/2){
			sort(w3+1,w3+t[3]+1);
			int q=t[3];
			for(int i=1;i<=q;i++){
				ans-=w3[i];
				t[3]--;
				if(t[3]==n/2) break;
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=3;i++) t[i]=0;
		for(int i=1;i<=n;i++) a[i].m=0; 
	}
	return 0;
}
