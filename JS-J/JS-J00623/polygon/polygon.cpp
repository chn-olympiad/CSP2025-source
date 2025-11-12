#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5005];
void dfs(int x,int num,int mn,int al){
	if((al>mn*2)&&num>=3){
		m++;
		m%=998244353;
		//cout<<x<<" "<<num<<" "<<mn<<" "<<al<<endl;
	}
	for(int i=x+1;i<n;i++){
		dfs(i,num+1,max(mn,a[i]),al+a[i]);
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		dfs(i,1,a[i],a[i]);
	}
	cout<<m;
	return 0;
}
