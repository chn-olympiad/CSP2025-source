#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		char c=s[i];
		if(c>='0'&&c<='9'){
			cnt[c-48]++;
		} 
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]--){
			cout<<i;
		}
	}
	return 0;
}
