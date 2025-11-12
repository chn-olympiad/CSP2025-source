#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+200;
string s;
int a[N],tot=0;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++tot]=s[i]-'0';
		}
	}
//	for(int i=1;i<=tot;i++){
//		cout<<a[i]<<" ";
//	}
	sort(a+1,a+1+tot,cmp);
	if(a[1]==0){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=tot;i++){
		cout<<a[i];
	}
	return 0;
}
