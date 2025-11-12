#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
char ch;
int a[maxn],sum;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>ch){
		if(ch>='0'&&ch<='9'){
			a[++sum]=ch-'0';
		}
	}
	sort(a+1,a+sum+1);
	for(int i=sum;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
