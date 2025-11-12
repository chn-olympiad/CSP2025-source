#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],x;
bool cmp(int z,int y){
	return z>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			x++;
			a[x]=int(s[i]-'0');
		}
	}sort(a+1,a+x+1,cmp);
	for(int i=1;i<=x;i++){
		cout<<a[i];
	}
	return 0;
}
