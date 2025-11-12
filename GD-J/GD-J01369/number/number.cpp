#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+10;
string s;
int a[M];
int num(){
	int cnt=1;
	for(auto i:s){
		if(isdigit(i)){
			a[cnt++]=i-'0';
		}
	}
	return cnt-1;
}
void sort1(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[j]<a[i])swap(a[i],a[j]);
		}
	}
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=num();
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--)cout<<a[i];
	cout<<endl;
	return 0;
}

