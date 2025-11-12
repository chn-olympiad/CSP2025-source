#include<bits/stdc++.h>
using namespace std;
string s;
int a[15],p;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[int(s[i]-'0')]++;
	}
	sort(a,a+p,cmp);
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++)cout<<i;
	}
	return 0;
} 
