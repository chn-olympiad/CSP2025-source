#include<bits/stdc++.h>
using namespace std;
string a;
long long b[1000005],num=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[num]=a[i]-48;
			num++;
		}
	}
	sort(b,b+num);
//	for(int i=0;i<num;i++){
//		cout<<b[i];
//	}
	if(b[num-1]==0){
		cout<<0;
		return 0;
	}
	for(int i=num-1;i>=0;i--){
		cout<<b[i];
	}
}