//number.cpp
#include<iostream>
#include<cstring>

using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long count[10]={0,0,0,0,0,0,0,0,0,0};
	string s;
	cin>>s;
	int cur=9,cnt=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			count[s[i]-'0']++;
			cnt++;
		}
	}
	while(cnt){
		if(count[cur]<=0){
			cur--;
			continue;
		}
		cout<<cur;
		cnt--;
		count[cur]--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
