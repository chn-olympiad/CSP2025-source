#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],p=0;	
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		a[p]=int(s[i])-48;
		if(a[p]>=0&&a[p]<=9)p++;	
	}
	sort(a,a+p);
	if(a[p-1]==0){
		cout<<0;
		return 0;
	}	
	for(int i=p-1;i>=0;i--){
		cout<<a[i];	
	}	
	return 0;
}
