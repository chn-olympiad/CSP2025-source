#include <bits/stdc++.h>
using namespace std;
string x;
int num[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	int len=x.size(),l=0;
	for(int i=0;i<len;i++){
		if(x[i]<='9' && x[i]>='0'){
			num[++l]=x[i]-'0';
		}
	}
	for(int i=1;i<l;i++){
		for(int j=i+1;j<=l;j++){
			if(num[j]>num[i]) swap(num[j],num[i]);
		}
	}
	for(int i=1;i<=l;i++) cout<<num[i];
	return 0;
}
