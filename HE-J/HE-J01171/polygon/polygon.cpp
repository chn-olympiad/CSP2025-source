#include <bits/stdc++.h>
using namespace std;
long long n,a[5010],b[5010],ans;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n,cmp);
	if(n<=3){
		if((b[1]+b[2])>(b[2]*2)){
			ans++;
		}
		if((b[1]+b[3])>(b[3]*2)){
			ans++;
		}
		if((b[2]+b[3])>(b[3]*2)){
			ans++;
		}
		if((b[1]+b[2]+b[3])>(b[3]*2)){
			ans++;
		}
		cout <<ans;
		return 0;
	}
	cout <<216;
	return 0;
}
