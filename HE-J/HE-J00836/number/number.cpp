#include<bits/stdc++.h>
using namespace std;
map<char,int> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a=s.size();
	int j=1;
	for(int i=0;i<a;i++){
		q[s[i]]++;
	}
	string ans;
	if(q['9']!=0){
		while(q['9']--){
			ans+='9';
		}
	}
	if(q['8']!=0){
		while(q['8']--){
			ans+='8';
		}
	}
	if(q['7']!=0){
		while(q['7']--){
		ans+='7';
		}
	}
	if(q['6']!=0){
		while(q['6']--){
			ans+='6';
		}
	}if(q['5']!=0){
		while(q['5']--){
			ans+='5';;
		}
	}
	if(q['4']!=0){
		while(q['4']--){
			ans+='4';
		}
	}
	if(q['3']!=0){
		while(q['3']--){
		ans+='3';
		}
	}
	if(q['2']!=0){
		while(q['2']--){
			ans+='2';
		}
	}
	if(q['1']!=0){
		while(q['1']--){
			ans+='1';
		}
	}
	if(q['0']!=0){
		while(q['0']--){
			ans+='0';
		}
	}
	cout<<ans;
	return 0;
}
