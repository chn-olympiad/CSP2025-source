#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
char a[N];
int ans = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len = s.length();
	if(len<=1){
		cout<<s;
	}
	for(int i=0;i<=len+1;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[i] = s[i];
			ans++;
		}
	}
	for(int i=0;i<=ans;i++){
		if(a[i]<=a[i+1]){
			swap(a[i],a[i+1]);
		}
	}
	for(int i=0;i<=ans;i++){
		if(a[i]<=a[i+1]){
			swap(a[i],a[i+1]);
		}
	}
	for(int i=0;i<=ans;i++){
		if(a[i]<=a[i+1]){
			swap(a[i],a[i+1]);
		}
	}
	for(int i=0;i<=ans;i++){
		if(a[i]<=a[i+1]){
			swap(a[i],a[i+1]);
		}
	}
	for(int i=0;i<=ans;i++){
		cout<<a[i];
	}
	return 0;
}
