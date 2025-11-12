#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt=0;
int l[5005];
int n;
void find(int thi,int ls,bool usee,int has){
	if(thi>n) return;
	if(usee){
		if((has>=3)&&(ls>(l[thi]))){
			cnt++;
		}
		find(thi+1,ls+l[thi],1,has+1);
		find(thi+1,ls+l[thi],0,has);
	}
	else{
		find(thi+1,ls,1,has+1);
		find(thi+1,ls,0,has);
	}
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	sort(l+1,l+n+1);
	find(1,0,0,0);
	find(1,0,1,1);
	cout<<cnt%998244353;
	return 0;
}
