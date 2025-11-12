//By Dream_Flynn(luogu name)
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int k=0;
	bool f=false;
	char c=getchar();
	while(!isdigit(c)){
		f=f||(c=='-');
		c=getchar();
	}
	while(isdigit(c)){
		k=(k<<3)+(k<<1)+(c^48);
		c=getchar();
	}
	return f?-k:k;
}
inline void write(int d,char end_ch='\n'){
	if(d<0){
		d=-d;
		putchar('-');
	}
	int stk[48],top=0;
	do{
		top++;
		stk[top]=d%10;
		d/=10;
	}while(d);
	for(int i=top;i;i--){
		putchar(stk[i]^48);
	}
	if(end_ch!='\0'){
		putchar(end_ch);
	}
}
const int N=1e5+5;
int n,a[N][4],cnt[4],ans,b[N],fr[N];
inline bool cmp(int d1,int d2){
	return b[d1]<b[d2];
}
inline void DFn_work(){
	for(int i=1;i<=n;i++){
		int m=fr[i];
		if(m==1){
			b[i]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
		}
		else if(m==2){
			b[i]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
		}
		else if(m==3){
			b[i]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
		}
	}
}
void Dream_Flynn(){
	vector<int> arr[4];
	cnt[1]=cnt[2]=cnt[3]=ans=0;
	n=read();
	for(int i=1;i<=n;i++){
		a[i][1]=read();
		a[i][2]=read();
		a[i][3]=read();
	}
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			cnt[1]++;
			arr[1].push_back(i);
			fr[i]=1;
			ans+=a[i][1];
		}
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			cnt[2]++;
			arr[2].push_back(i);
			fr[i]=2;
			ans+=a[i][2];
		}
		else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
			cnt[3]++;
			arr[3].push_back(i);
			fr[i]=3;
			ans+=a[i][3];
		}
	}
	int t=0;
	for(int i=1;i<=3;i++){
		if(cnt[i]>(n>>1)){
			t=i;
		}
	}
	if(t==0){
		write(ans);
		return;
	}
	DFn_work();
	sort(arr[t].begin(),arr[t].end(),cmp);
	for(int i:arr[t]){
		if(cnt[t]<=(n>>1)){
			break;
		}
		ans-=b[i];
		cnt[t]--;
	}
	write(ans);
}
signed main(){
	//freopen("club5.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		Dream_Flynn();
	}
	return 0;
}
