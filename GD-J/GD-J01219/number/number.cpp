#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(number,"w",number.in);
	freopen(number,"r",number.out);
	string s;
	cin>>s;
	vector<int> str;
	int len=0;
	int s1[9100]={0};
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			char c=s[i];
			int index=c-'0';
			s1[index]+=1;
		}
	}
	for(int i=9;i>=0;i--){
		while(s1[i]--) cout<<i;
	}
	return 0;
}
