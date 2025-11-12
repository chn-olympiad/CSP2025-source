#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[1000005];
int f=0;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			f++;
			a[f]=s[i]-'0';
		}
	}
	sort(a+1,a+1+f,cmp);
//	for(int i=1;i<=f;i++){
//		cout<<a[i]<<" ";
//	}
	for(int i=1;i<=f;i++){
		cout<<a[i];
	}
	return 0;
}
