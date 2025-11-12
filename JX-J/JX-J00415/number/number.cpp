#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000001],c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[c]=int(s[i])-48;
			c++;
		}
	}
	sort(a,a+c,cmp);
	for(int i=0;i<c;i++){
		cout<<a[i];
	}
    return 0;
}
