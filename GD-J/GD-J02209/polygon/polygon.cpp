#include <bits/stdc++.h>
using namespace std;
int num[1001];
long long aaaaa(int a){
	int ans=1;
	for(int i=1;i<=a;i++){
		ans*=i;
	}
	return ans;
}
int main(){
	freopen("polygon.in",'r',stdin);
	freopen("polygon.out",'w',stdout);
	int n,pop=0,all=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		pop=max(pop,num[i]);
		all+=num[i];
	}
	c=rand(1,aaaaa(all)/aaaaa[pop]);
	cout<<pop;
	return 0;
}
