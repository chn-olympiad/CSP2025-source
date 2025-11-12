#include <bits/stdc++.h>
using namespace std;
int num[1000005];
string ans;
string s;
int turn(char c){
	return c-'0';
}
bool bijiao(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int xiabiao=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[xiabiao] = turn(s[i]);
			xiabiao++;
		}
	}
	sort(num,num+xiabiao,bijiao);
	for(int i=0;i<xiabiao;i++){
		ans += num[i]+'0';
	}
	cout<<ans;
	return 0; 
}
