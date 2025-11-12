#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int T,n;
int a[N][4],bel[N];
int s[4];
ll ans=0;
int st[N],top;
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
cin>>T;
while(T--){
	s[1]=s[2]=s[3]=0;ans=0;top=0;
//	cin>>n;
	n=read();
	for(int i=1;i<=n;i++){
//		cin>>a[i][1]>>a[i][2]>>a[i][3];
		a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		a[i][0]=max(a[i][1],max(a[i][2],a[i][3]));
		ans+=a[i][0];
		if(a[i][0]==a[i][1]) s[1]++,bel[i]=1;
		else if(a[i][0]==a[i][2]) s[2]++,bel[i]=2;
		else s[3]++,bel[i]=3; 
	}
	if(s[1]>n/2){
		for(int i=1;i<=n;i++){
			if(bel[i]==1){
				st[++top]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			}
		}
		sort(st+1,st+top+1);
		for(int i=1;i<=s[1]-n/2;i++) ans-=st[i];
		
	}
	else if(s[2]>n/2){
		for(int i=1;i<=n;i++){
			if(bel[i]==2){
				st[++top]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			}
		}
		sort(st+1,st+top+1);
		for(int i=1;i<=s[2]-n/2;i++) ans-=st[i];
		
	}
	else if(s[3]>n/2){
		for(int i=1;i<=n;i++){
			if(bel[i]==3){
				st[++top]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
			}
		}
		sort(st+1,st+top+1);
		for(int i=1;i<=s[3]-n/2;i++) ans-=st[i];
		
	}
	cout<<ans<<'\n';
}
	return 0;
}
