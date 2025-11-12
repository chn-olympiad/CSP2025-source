#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int b){
	if(x>b){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=int(s[i]-'0');
		//	cout<<s[i]<<' ';
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}