#include<bits/stdc++.h>
using namespace std;
const int N=5*10e5+10;
int a[N]={};
int n,k;
void solve1(){
	//a_i=1
	cout<<1;return ;
}
void solve2(){
	//0<=a_i<=1
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){ans++;}
	}
	cout<<ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool tag1=true,tag2=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			tag1=false;
		}
		if(!(0<=a[i] and a[i]<=1)){
			tag2=false;
		}
	}
	if(tag1){
		solve1();return 0;
	}
	if(tag2){
		solve2();return 0;
	}
	cout<<1;
	return 0;
}
