#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	if(s.size()==1){
		cout<<s[0];
		return 0;
	}
	if(s.size()==2){
		for(int i=0;i<2;i++){
			a[i]=int(s[i]-48);
		}
		if(a[1]<10&&a[0]>10){
			cout<<a[1];
		}else if(a[1]>10&&a[0]<10){
			cout<<a[0];
		}else if(a[1]<10&&a[2]<10){
			if(a[1]<a[0]){
				cout<<a[0]<<a[1];
			}else{
				cout<<a[1]<<a[0];
			}
		}
		return 0;
	}
	int n=s.size();
	int sum=1;
	for(int i=0;i<n;i++){
		if(s[i]<'0'||s[i]>'9')continue;
		a[sum]=int(s[i]-48);
		sum++;
	}
	sort(a+1,a+sum);
	for(int i=sum-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
