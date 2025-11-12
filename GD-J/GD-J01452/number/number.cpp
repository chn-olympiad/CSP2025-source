#include<bits/stdc++.h>
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
	int idx=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[idx++]=(int)(s[i]-'0');
	}
	sort(a+1,a+1+idx,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<idx;i++)cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
