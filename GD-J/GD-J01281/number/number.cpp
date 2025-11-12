#include<bits/stdc++.h>
using namespace std;
int a[1145141];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k=1;
	if(s.size()==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k++]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1,greater<int>());
	for(int i=1;i<=k;i++){
		printf("%d",a[i]);
	}
	return 0;
} 
