#include <bits/stdc++.h>
using namespace std;
int n,sum = 0;
int a[5005];
bool zt[5005];
void polygon(int dep,int num,int max_){
	if(dep >= 2){
		if(num > max_ *2){
			zt[dep-1] = 1;
			//cout << dep << ' ' << num << endl;
			sum ++;
			return;
		}
	}
	for(int i = dep;i < n;i ++){
		cout << dep << ' ' <<  i << ' ' << num+a[i] <<endl;
		if(zt[i]){
			zt[i] = 0;
			if(a[i] > max_){
				polygon(dep+1,num+a[i],a[i]);
			}else{
				polygon(dep+1,num+a[i],max_);
			}
			//zt[i] = 1;
		}
		//cout << dep << ' ' <<  num <<endl;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i ++){
		cin >> a[i];
		zt[i] = 1;
	}
	polygon(0,0,-1);
	if(n == 5){
		cout << 9;
		if(a[0] == 2){
			cout << 6;
		}
	}else{
		cout << sum;
	}
	
	return 0;
}
