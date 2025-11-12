#include <bits/stdc++.h>
using namespace std;
#define N 998244353
int n,a[5010],cnt=0;
void polygon(int m,int sum,int x,int maxn){
	if(x>n){
		if(m>=3&&sum>2*maxn) cnt++;
		return ;
	}
	
	int newsum,newmax;
	newsum=(sum%N+a[x]%N)%N;
	newmax=max(maxn,a[x]);
	polygon(m+1,newsum,x+1,newmax);
	polygon(m,sum,x+1,maxn);

}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	polygon(0,0,0,0);
	cout<<cnt/2;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
