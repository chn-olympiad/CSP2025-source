#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[10000001]={};
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int t=0;
	cin >>s;
	for(int i=0 ; i<s.size() ; i++){
		if(s[i]=='0'){
			cnt[t]=0;
			t++;
		}
		if(s[i]=='1'){
			cnt[t]=1;
			t++;
		}
		if(s[i]=='2'){
			cnt[t]=2;
			t++;
		}
		if(s[i]=='3'){
			cnt[t]=3;
			t++;
		}
		if(s[i]=='4'){
			cnt[t]=4;
			t++;
		}
		if(s[i]=='5'){
			cnt[t]=5;
			t++;
		}
		if(s[i]=='6'){
			cnt[t]=6;
			t++;
		}
		if(s[i]=='7'){
			cnt[t]=7;
			t++;
		}
		if(s[i]=='8'){
			cnt[t]=8;
			t++;
		}
		if(s[i]=='9'){
			cnt[t]=9;
			t++;
		}
	}
	
	sort(cnt,cnt+t,cmp);
	for(int i=0 ; i<t ; i++){
		cout <<cnt[i];
		
	}
}
