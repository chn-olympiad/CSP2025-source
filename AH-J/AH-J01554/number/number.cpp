	#include<bits/stdc++.h>
	using namespace std;
	char ch[100010];
	int main(){
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
		string s;
		cin>>s;
		int cnt=0;
		for(int i=0;i<s.size();i++){
			if(s[i]>='0'&&s[i]<='9'){
				ch[++cnt]=s[i];
			}
		}
		sort(ch+1,ch+cnt+1);
		for(int i=cnt;i>=1;i--){
			cout<<ch[i];
		}
		return 0;
	}
