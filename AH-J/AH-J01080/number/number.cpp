#include<bits/stdc++.h>
using namespace std;
int a[109];
int main(){
	freopen("numbner.in","r",stdin);
	freopen("numbner.out","w",stdout);
	int n;
	string s;
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){ 
			cout<<i;
			a[i]--;
		}
	}
		return 0;
}
