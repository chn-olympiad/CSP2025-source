#include<bits/stdc++.h>
using namespace std;
int cnt[10],num;
string s,p;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}for(int i=9;i>=0;i--){
		while(cnt[i]){
			printf("%d",i);
			cnt[i]--;
		}
	}
} 
