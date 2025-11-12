#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int sum=0,x=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')x=-1;
		ch=getchar();
	}
	while(ch>='0'&&(ch<='9')){
		sum=(sum<<3)+(sum<<1)+(ch^48);
		ch=getchar();
	}
	return sum*x;
}
int n,a[200010][5],sum[6],fg[200010],mx,ans,xk,smk,su[200010],ct;
void work(){
	n=read();
	ct=0;ans=0;
	memset(sum,0,sizeof sum);
	for(int i=1;i<=n;i++){
		mx=0;
		for(int j=1;j<=3;j++){
			a[i][j]=read();
			mx=max(mx,a[i][j]);
		}
		if(a[i][1]==mx)sum[1]++,fg[i]=1;
		else if(a[i][2]==mx)sum[2]++,fg[i]=2;
		else sum[3]++,fg[i]=3;
		ans+=mx;
	}
	if(sum[1]<=n/2&&(sum[2]<=n/2)&&(sum[3]<=n/2)){
		cout<<ans<<endl;
		return ;
	}
	if(sum[1]>n/2)xk=1;
	else if(sum[2]>n/2)xk=2;
	else xk=3;
	smk=sum[xk]-n/2;
	for(int i=0;i<=n;i++){
		if(fg[i]==xk){
			if(xk==1){
				su[++ct]=max(a[i][2],a[i][3])-a[i][1];
			}else if(xk==2){
				su[++ct]=max(a[i][1],a[i][3])-a[i][2];
			}else {
				su[++ct]=max(a[i][1],a[i][2])-a[i][3];
			}
		}
	}
	sort(su+1,su+1+ct,greater<int>());
	for(int i=1;i<=smk;i++){
		ans+=su[i];
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	_=read();
	while(_--)work();
	return 0;
}
//wjh
