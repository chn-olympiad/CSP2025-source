#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int T,n,a[maxn][4];
priority_queue<int> q[4];
inline int read(){
	int sum=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		sum=(sum<<3)+(sum<<1)+ch-'0';
		ch=getchar();
	}
	return sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		while(q[1].size()) q[1].pop();
		while(q[2].size()) q[2].pop();
		while(q[3].size()) q[3].pop();
		int sum=0;
		n=read();
		for(int i=1;i<=n;++i) a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		for(int i=1;i<=n;++i){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				if(q[1].size()<n/2) sum+=a[i][1],q[1].push(max(a[i][2],a[i][3])-a[i][1]);
				else{
					if(q[1].top()<max(a[i][2],a[i][3])-a[i][1]) sum+=max(a[i][2],a[i][3]);
					else sum+=q[1].top()+a[i][1],q[1].pop(),q[1].push(max(a[i][2],a[i][3])-a[i][1]);
				}
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				if(q[2].size()<n/2) sum+=a[i][2],q[2].push(max(a[i][1],a[i][3])-a[i][2]);
				else{
					if(q[2].top()<max(a[i][1],a[i][3])-a[i][2]) sum+=max(a[i][1],a[i][3]);
					else sum+=q[2].top()+a[i][2],q[2].pop(),q[2].push(max(a[i][1],a[i][3])-a[i][2]);
				}
			}
			else{
				if(q[3].size()<n/2) sum+=a[i][3],q[3].push(max(a[i][1],a[i][2])-a[i][3]);
				else{
					if(q[3].top()<max(a[i][1],a[i][2])-a[i][3]) sum+=max(a[i][1],a[i][2]);
					else sum+=q[3].top()+a[i][3],q[3].pop(),q[3].push(max(a[i][1],a[i][2])-a[i][3]);
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
// 15:05 T1 passed
// I AK CSP-S
// You have no eggs