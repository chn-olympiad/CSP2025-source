#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int* a;
bool check(int n,int m){
	int sum=0,max=-114514;
	for(int i=n;i<m;i++){
		sum+=a[i];
		if(max<a[i])max=a[i];
	}
	if(sum>max*2)return 1;
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	a=new int(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=0;j<n;j++){
			if(check(j,j+i))cnt++;
		}
	}
	cout<<cnt%998244353;
	delete a;
	return 0;
}
