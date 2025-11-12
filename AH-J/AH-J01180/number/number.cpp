#include<bits/stdc++.h>
using namespace std;
string s;
int top,l[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<=len-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			l[top]=s[i]-'0';
			top++;
		}
	}
	sort(l,l+top,cmp);
	if(l[0]==0){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<=top-1;i++){
		cout<<l[i];
	}
	return 0;
}
