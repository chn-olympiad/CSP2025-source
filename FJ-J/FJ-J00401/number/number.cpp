#include<bits/stdc++.h>
using namespace std;
string b;
int a[1000005],s,l,f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	s=b.size();
	for(int i=0;i<s;i++){
		if(b[i]>='0'&&b[i]<='9'){
			a[++l]=int(b[i]-48);
		}
	}
	sort(a+1,a+l+1);
	for(int i=l;i>=1;i--){
		if(f==1){
			cout<<a[i];
		}
		if(f==0&&a[i]!=0){
			cout<<a[i];
			f=1;
		}
	}
	return 0;
}
