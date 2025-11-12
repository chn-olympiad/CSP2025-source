#include<bits/stdc++.h>
using namespace std;
int a[1145140]; 
int n,k;
void solve1(){
	int cnt1 = 0,cnt2 = 1;
	for(int i = 1;i <= n;i++){
		if(a[i] == 0){
			cnt1++;
		}
	}
	for(int i = 1;i <= n;i++){
		if(a[i] == 1 && a[i] == a[i - 1]){
			cnt2++;
		}else{
			cnt1+=cnt2 / 2;
			cnt2 = 1;
		}
	}
	cout<<cnt1<<endl;
}
void solve2(){
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] == 1){
			cnt++;
		}
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(k == 0){
		solve1();
	}
	if(k == 1){
		solve2();
	}
	return 0;
}

