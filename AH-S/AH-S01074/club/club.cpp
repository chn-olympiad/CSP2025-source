#include<bits/stdc++.h>
using namespace std;
	long long T,N,a[100005],b[100005],c[100005],ans=0,sa,sb,sc;
void dfs(long long n,long long size,long long num){
	if(size==1)num+=a[n];
	if(size==2)num+=b[n];
	if(size==3)num+=c[n];
	if(sa<N/2){
		sa++;
		//cout<<num<<' ';
		dfs(n+1,1,num);
		sa--;
	}
	if(sb<N/2){
		sb++;
		//cout<<num<<' ';
		dfs(n+1,2,num);
		sb--;
	}
	if(sc<N/2){
		sc++;
		//cout<<num<<' ';
		dfs(n+1,3,num);
		sc--;
	}
	if(n>=N){
		//cout<<num<<endl;
		if(num>ans)ans=num;
		return;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sa=sb=sc=0;
		ans=0;
		sa++;
		dfs(0,1,0);
		sa--;
		sb++;
		dfs(0,2,0);
		sb--;
		sc++;
		dfs(0,3,0);
		sc--;
		cout<<ans<<endl;
	}
	return 0;
}
