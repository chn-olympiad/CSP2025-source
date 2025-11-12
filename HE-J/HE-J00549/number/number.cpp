#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),tot=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++tot]=s[i]-'0';
		}
	}
	sort(a+1,a+tot+1);
	if(a[tot]==0){
		cout<<0;
	}else{
		for(int i=tot;i>=1;i--){
			cout<<a[i];
		}
	}
	return 0;
}
