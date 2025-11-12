#include<bits/stdc++.h>
#define int long long
using namespace std;
int pp[9000001];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a; 
	int num = 0;
	int x=0;
	for(int i=0;i<a.size();i++){
		if('0'<=a[i] and a[i]<='9'){
			int ans = a[i]-48;
			pp[x]=ans;
			num++;
			x++;
			//cout<<ans<<"     ";
			//cout<<n[i]<<" ";
		}
	}
//	for(int i=0;i<num;i++){
//		cout<<pp[i]<<" ";
//	}
	sort(pp,pp+num,cmp);
	for(int i=0;i<num;i++){
		cout<<pp[i];
	}
	return 0;
}
