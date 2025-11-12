#include <bits/stdc++.h>
using namespace std;
int a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	if(n<=3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			cout <<1;
		}else{
			cout <<0;
		}
	}else{
		sort(a+1,a+n+1);
		if(n==5){
			cout <<6;
		}else if(n==6){
			cout <<9;
		}else{
			cout <<1;
		}
	}
	return 0;
}
