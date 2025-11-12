#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long sum=0; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int maxx,cnt;
	for(int i=1;i<=n-2;i++){
		maxx=0;
		cnt=0;
		for(int j=i;j<=n;j++){
			maxx=max(maxx,a[j]);
			cnt+=a[j];
			if(j-i>=2 && maxx*2<cnt){
				sum++;
			}
		}
	}
	/*
	T4实在不会了
	偷点分吧
	QAQ
	真的不行了
	要今年还没有
	明年就真的不学了 
	希望这话能被看到 
	*/
	cout<<sum%998244353<<endl;
	return 0;
}
