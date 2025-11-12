#include<bits/stdc++.h>
using namespace std;

const int N=5*1e3+5;
int n,a[N],ans;

void f(int cnt,int sum,int x,int d){
	if(cnt==x+1){
		if(sum>a[d-1]*2){
			ans++;
			cout<<d<<endl;
		}
	}
	for(int i=d+1;i<=x;i++){
		f(cnt+1,sum+a[i],x,d);
	}
	return ;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		f(0,0,i,0);
	}
	cout<<ans;
	return 0;
} 
//5
//1 2 3 4 5
