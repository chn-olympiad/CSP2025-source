/*	
能上抽象行为大赏吗？（Doge

今年再考不上CSP-S 1=就要退役了。

此举不成功，便成zorrer。 

luogu uid: 982056 （liyp）

可恶的 CCF 给我们配的电脑是 I3-2130 @3.4GB，内存才3.5GB，Windows7 

考不好我就说是电脑害的。 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 10;
int n,a[MAXN][4],sum; 

void solve() 
{
	sum=0;
	vector<int >a1,a2,a3;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int maxn=0,maxn2=0;
		if(a[i][1]>=maxn){
			maxn2=maxn;
			maxn=a[i][1];
		}
		else if(a[i][1]>maxn2){
			maxn2=a[i][1];
		}
		if(a[i][2]>=maxn){
			maxn2=maxn;
			maxn=a[i][2];
		}
		else if(a[i][2]>maxn2){
			maxn2=a[i][2];
		}
		if(a[i][3]>=maxn){
			maxn2=maxn;
			maxn=a[i][3];
		}
		else if(a[i][3]>maxn2){
			maxn2=a[i][3];
		}
		if(a[i][1]>=a[i][2] and a[i][1]>=a[i][3]){
			a1.push_back(maxn-maxn2);
		}
		else if(a[i][2]>=a[i][1] and a[i][2]>=a[i][3]){
			a2.push_back(maxn-maxn2);
		}
		else{
			a3.push_back(maxn-maxn2);
		}
		sum+=maxn;
	} 
	sort(a1.begin(),a1.end());
	sort(a2.begin(),a2.end());
	sort(a3.begin(),a3.end());
	if(a1.size()>n/2){
		for(int i=0;i<a1.size() and a1.size()-i-1>=n/2;i++){
			sum-=a1[i];
		}
	}
	if(a2.size()>n/2){
		for(int i=0;i<a2.size() and a2.size()-i-1>=n/2;i++){
			sum-=a2[i];
//			cout<<a2[i]<<" ";
		}
	}
	if(a3.size()>n/2){
		for(int i=0;i<a3.size() and a3.size()-i-1>=n/2;i++){
			sum-=a3[i];
		}
	}
	cout<<sum<<"\n";
	return; 
} 
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve(); 
	} 
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
