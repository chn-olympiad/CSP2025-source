#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#define ll long long
#define fg cout<<"！！！！！！！！！！！！！！！！！！"<<endl
using namespace std;
const int N=1e5+5,mod=998244353;
int T,n,a[N][4],b[N][4],f[N],g[N];
ll ans;
priority_queue<int,vector<int>,greater<int> >q1,q2,q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i][1]=a[i][1];
			b[i][2]=a[i][2];
			b[i][3]=a[i][3];
			sort(b[i]+1,b[i]+4);
			f[i]=b[i][3]-b[i][2];
			if(a[i][1]==b[i][3]) g[i]=1;
			if(a[i][2]==b[i][3]) g[i]=2;
			if(a[i][3]==b[i][3]) g[i]=3;
		}
		ans=0;
		int s1=0,s2=0,s3=0;
		for(int i=1;i<=n;i++){
			ans+=b[i][3];
			if(g[i]==1) q1.push(f[i]);
			if(g[i]==2) q2.push(f[i]);
			if(g[i]==3) q3.push(f[i]);
		}
		while(q1.size()>n/2){
			ans-=q1.top();
			q1.pop();
		}
		while(q2.size()>n/2){
			ans-=q2.top();
			q2.pop();
		}
		while(q3.size()>n/2){
			ans-=q3.top();
			q3.pop();
		}
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		cout<<ans<<endl;
	}
	return 0;
}
