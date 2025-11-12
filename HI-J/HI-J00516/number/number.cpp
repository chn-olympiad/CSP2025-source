#include<bits/stdc++.h>
using namespace std;
int a[1000000+5];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int tmp=0;
	string str;
	cin>>str;
	int n=str.size();
	for(int i=0;i<n;i++){
		if(str[i]>='0' && str[i]<='9'){
			a[tmp++]=str[i]-'0';
		}
	}
	sort(a,a+tmp);
	for(int i=tmp-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
