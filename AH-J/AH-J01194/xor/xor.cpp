#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int n,m,ans;
int num[N];
int xo[N];
int cal(int a,int b);
int bfs(int pre,int nnum);
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>num[i];
	}
	for (int i=1;i<=n;i++){
		int next=bfs(i,num[i]);
		if (next!=-1){
			ans++;
			i=next;
		}
		
	}
	cout<<ans;
	return 0;
}
int bfs(int pre,int nnum){
	if (nnum==m){
		return pre;
	}
	for (int i=pre+1;i<=n;i++){
		nnum=cal(nnum,num[i]);
		if (nnum==m){
			return i;
		}
		
	}
	return -1;
	
}
int  cal(int a,int b){
	int i=0;
	int c=0;
	while (a&&b){
		i++;
		int nx=a%2;
		int ny=b%2;
		if (nx!=ny){
			int num=1;
			for (int j=1;j<i;j++){
				num=num*2;
			}
			c+=num;
		}
		a/=2;
		b/=2;
	}
	if (a){
		i++;
		int num=1;
		for (int j=1;j<i;j++){
			num=num*2;
		}
		c+=num;
		a/=2;
	}
	if (b){
		i++;
		int num=1;
		for (int j=1;j<i;j++){
			num=num*2;
		}
		c+=num;
		b/=2;
	}
	return c;
}
