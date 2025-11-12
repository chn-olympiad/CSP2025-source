#include<bits/stdc++.h>
using namespace std;
int n,m,sr,a[105][105],b[10005];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>sr;
	int rank=1;
	// 1. 计算出小r在第几位
	for(int i=2;i<=n*m;i++){
		cin>>b[i];
		if(b[i]>sr){
			rank++;
		}
	}
	// 2. 计算出小r的列以及排序顺序
	int c=(rank-1)/n+1;
	int ord=c%2,l;//奇数即上至下，偶数为下到上
	// 3. 计算出小r的位置，输出
	if(ord==1){
		l=rank-(c-1)*n;
	}else{
		l=n-(rank-(c-1)*n)+1;
	}
	cout<<c<<" "<<l;
	return 0; 
}
