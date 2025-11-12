#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,b;
	cin>>s;
	int t=0;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[t]=s[i]-'0';
			t++;
		}
	}for(int i=0;i<=t-1;i++){
		for(int i=1;i<=t-1;i++){
			if(b[i]>b[i-1]){
				swap(b[i],b[i-1]);
			}
		}
	}
	
	for(int i=0;i<=t-1;i++){
		cout<<(int)b[i];
	}
}