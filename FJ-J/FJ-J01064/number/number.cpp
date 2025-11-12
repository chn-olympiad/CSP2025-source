#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	if(a.length()<=1&&a[0]>='0'&&a[0]<='9'){
		cout<<a[0]-'0';
		return 0;
	}
	int b[1000001]={},sum=1;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[sum++]=a[i]-'0';
		}
	}
	sort(b+1,b+sum-1);
	for(int i=sum-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;	
}
