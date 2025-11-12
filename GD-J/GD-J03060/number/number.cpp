#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[j++]=s[i]-'0';
		}
	}
	sort(a+1,a+j,cmp);
	bool flag=1;
	if(a[1]==0){
		cout<<0;
		flag=0;
	}
	if(flag){
		for(int i=1;i<j;i++){
			cout<<a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
