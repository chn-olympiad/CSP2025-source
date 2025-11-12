#include<bits/stdc++.h>
using namespace std;
char in[1000005];
int nums[1000005],n,nus[10];
void st(){
	for(int i=1;i<=n;i++){
		nus[nums[i]]++;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>in;
	for(int i=0;;i++){
		if(in[i]=='\0') break;
		if(in[i]>='0' && in[i]<='9'){
			n++;nums[n]=in[i]-'0';
		}
	}
	st();
	for(int i=9;i>=0;i--){
		for(int j=1;j<=nus[i];j++) cout<<i;
	}
	return 0;
}
//25-11-01 at SDFZ
//How are you today?
