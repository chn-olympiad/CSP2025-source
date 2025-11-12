#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int ans;
int ans_1[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			ans_1[ans++]=s[i]-'0';
		}
	}
	sort(ans_1,ans_1+ans,cmp);
	for(int i=0;i<ans;i++){
		cout<<ans_1[i];
	}
	return 0;
}
