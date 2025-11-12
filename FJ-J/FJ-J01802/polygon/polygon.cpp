#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,a[5005],ans;
void f(int x,int y,int z){
	if(y>=3 && x>=z*2){
		//cout<<x<<y<<z;
		ans++;
		return;
	}
	//cout<<x<<y<<z;
	int cnt=z;
	for(int i=x+1;i<n;i++){
		cnt+=a[i];
		f(cnt,y+1,a[i]); 
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	f(0,1,a[0]);
	ans=n-1+n-2+n-3;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

