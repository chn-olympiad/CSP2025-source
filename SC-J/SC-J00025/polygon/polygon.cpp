#include<bits/stdc++.h>
using namespace std;
const int N=5*1e3+10;
int a[N],n,sum,idx;
long long cnt,ac=998244353;
void search(int id){
	for(int i=id;i<=n;i++){
		sum+=a[i];
		if(sum>2*a[idx]){
			cnt++;
		} 
		if(i<n)
			search(i+1);
		sum-=a[i];
	}
	return;
}
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	idx=n-2;
	for(idx;idx>=1;idx--){
		sum=a[idx];
		search(idx+1);
		cnt%=ac;
	}
	cout<<cnt%ac<<'\n';
	return 0;
}