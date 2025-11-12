#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q;
int a[100005],xr[100005],ai[100005];
//int xrhe(int l,int r){
//	return xr[l-1]^x[r];
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	int n,k,sum=0,cnt=0,fl=1,fll=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)fl=0;
		if(a[i]!=0&&a[i]!=1)fll=0;
		ai[i]=a[i]^k;
		if(ai[i]!=0)q.push(ai[i]);
		else cnt++;
	}
	if(fl){
		cout<<n/2<<'\n';
		exit(0);
	}
	if(fll){
		int cntt=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)cntt++;
			}
			for(int i=1;i<n;i++){
				if(a[i]==1&&a[i+1]==1)cntt++,i++;
			}	
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1)cntt++;
			}
		}
		cout<<cntt<<'\n';
		exit(0);
	}
//	for(int i=1;i<=n;i++){
//		xr[i]=xr[i-1]^a[i];
//	}
	int ct=0;
	while(!q.empty()&&ct<=q.size()){
		int t=q.top();
		q.pop();
		if(q.empty())break;
		int tt=q.top();
		q.pop();
		int xx=t^tt;
		ct++;
		if(xx==0){
			cnt++;
		}else{
			q.push(xx);
		}
	}
	cout<<cnt<<'\n';
	return 0;
}/*
4 2
2 1 0 3
4 3
2 1 0 3
4 0
2 1 0 3
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

*/
