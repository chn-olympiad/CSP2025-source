#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number","w",stdin);
	freopen("number","r",stdout);
	string s;
	cin>>s;
	long long a[1005]={0};
	int d=s.size();
	for(int i=0;i<s.size();i++){
		if(s[i]>'0'&&s[i]<='9'){
			a[i]=s[i]-48;
		}
	}
	sort(a+0,a+0+s.size(),cmp);
	for(int i=0;i<s.size();i++){
		if(a[i]<0||a[i]>9){
			a[i]=-1;
		}
	}
	for(int i=0;i<d;i++){
		if(a[i]!=-1){
		cout<<a[i];
		}
	}
	return 0;	
	fclose("number",stdin);
	fclose("number",stdout);
} 