#include<bits/stdc++.h>
using namespace std;
int a[1000005],ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l = s.size();
	for(int i =0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[i]=s[i]-'0';
			ans++;
		}
	}
	sort(a,a+l,cmp);
	for(int i =0;i<ans;i++){
		cout<<a[i];
	}
}
