#include<bits/stdc++.h>//GZ-S00064 安顺市第二高级中学 刘科 
using namespace std;
const int kMaxN=1e5+7;
int n,a[kMaxN],b[kMaxN],c[kMaxN],ans,chose[5],t;
bool ac=1;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return f*x;
}
void DFS(int d,int hp){
	if(d==n+1){
		ans=max(ans,hp);
		return ;
	}
	if(chose[1]<n/2){
		chose[1]++;
		DFS(d+1,hp+a[d]);
		chose[1]--;
	}
	if(chose[2]<n/2){
		chose[2]++;
		DFS(d+1,hp+b[d]);
		chose[2]--;
	}
	if(chose[3]<n/2){
		chose[3]++;
		DFS(d+1,hp+c[d]);
		chose[3]--;
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin.tie(0)->sync_with_stdio(0);
	for(cin>>t;t--;){	
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read(),b[i]=read(),c[i]=read();
		if(b[i]!=0||c[i]!=0){
			ac=0;
		}
	} 
	if(ac){
		sort(a+1,a+n+1);
		for(int i=0;i<n/2;i++){
			ans+=a[n-i]; 
		}
	}else{
	DFS(1,0);
	}
	cout<<ans<<'\n';
	ans=0;
	}
	return 0;
}
