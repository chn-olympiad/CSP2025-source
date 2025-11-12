/*
妈妈我现在就要玩原神！

欢唱，以我之名！

froepen
feropen
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void write(int k){
	if(k<0){
		k=-k;
		putchar('-');
	}
	if(k>9)
		write(k/10);
	putchar(k%10+'0');
}
/*
简单贪心,先分配到最大的,然后按照调整的贡献贪心即可
*/
int t,n,a[100005][3],num[3],vis[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		num[0]=num[1]=num[2]=0;
		ll ans=0;
		for(int i=1;i<=n;i++){
			a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
				num[0]++,ans+=a[i][0],vis[i]=0;
			else if(a[i][1]>=a[i][2])
				num[1]++,ans+=a[i][1],vis[i]=1;
			else
				num[2]++,ans+=a[i][2],vis[i]=2;
		}
		int num1=0;
		vector<int> q;
		if(num[0]>n/2){
			num1=num[0]-n/2;
			for(int i=1;i<=n;i++){
				if(vis[i]==0)
					q.emplace_back(max(a[i][1],a[i][2])-a[i][0]);
			}
		}
		else if(num[1]>n/2){
			num1=num[1]-n/2;
			for(int i=1;i<=n;i++){
				if(vis[i]==1)
					q.emplace_back(max(a[i][0],a[i][2])-a[i][1]);
			}
		}
		else if(num[2]>n/2){
			num1=num[2]-n/2;
			for(int i=1;i<=n;i++){
				if(vis[i]==2)
					q.emplace_back(max(a[i][0],a[i][1])-a[i][2]);
			}
		}
		sort(q.begin(),q.end());
		reverse(q.begin(),q.end());
		for(int i=0;i<num1;i++){
			ans+=q[i];
		}
		write(ans),putchar('\n');
	}
	return 0;
}