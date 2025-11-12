#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool down(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[ans]=s[i]-'0';
			ans++;
		}
	}
	sort(a,a+ans,down);
	for(int i=0;i<ans;i++){
		cout<<a[i];
	}
	return 0;
}
