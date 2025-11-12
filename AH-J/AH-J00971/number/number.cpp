#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x;
	cin>>x;
	int s=0;
	for(auto i:x){
		if(i>='0'&&i<='9'){
			a[++s]=i-'0';
		}
	}
	sort(a+1,a+s+1,greater<int>());
	for(int i=1;i<=s;i++){
		cout<<a[i];
	}
	return 0;
}
