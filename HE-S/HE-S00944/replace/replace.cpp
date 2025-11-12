#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

long long n,q,answer=0;
struct stri{
	string s1;
	string s2;
	int def,def2;
};
stri s[N],s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin >> s[i].s1 >>s[i].s2;
		//找第一个变化的字母的下标 
		for(int j=0;j<s[i].s1.length();j++){
			if(s[i].s1[j] !=s[i].s2[j]){
				s[i].def = j;
				break;
			}
		}
	}
	for(int i=0;i<q;i++){
		answer=0;
		cin >> s2.s1 >>s2.s2;
		//询问串长度不等 
		if(s2.s1.length() != s2.s2.length()){
				cout<< answer<<'\n';
				continue;
		}
		//第一个替换位点 
		for(int j=0;j<s2.s1.length();j++){
			if(s2.s1[j] != s2.s2[j]){
				s2.def = j;
				break;
			}
		}
		for(int j=s2.s1.length()-1;j>=0;j--){
			if(s2.s1[j] != s2.s2[j]){
				s2.def2 = j;
				break;
			}
		}
		//查找可替换的字符串的总数 
		for(int j=0;j<n;j++){
			int l=s[j].def;
			if((s[j].s1.length() > s2.s1.length()) || (l>s2.def)) {
				continue;
			}
			//如果替换字符串不能覆盖所有区间，则跳过 
			if(s[j].s1.length()-s[j].def-1 < s2.def2-s2.def){
				continue;
			}
			//
			bool flag = true;
			for(int k=0 ;k<s[j].s1.length() ;k++){
				if(s[j].s1[k] != s2.s1[k+s2.def-l] || s[j].s2[k] != s2.s2[k+s2.def-l]){
					flag = false;
					break; 
				}
			}
			//
			if(flag){
				answer++;
			}
			
		}
		cout<< answer<<'\n';
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
