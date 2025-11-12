#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long a[1005]={0},ans=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[ans]=s[i]-'0';
			ans++;
		}
	}
	for(int i=0;i<ans;i++){
		for(int j=i;j<ans;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
		cout<<a[i];
	}
	return 0;
} 
