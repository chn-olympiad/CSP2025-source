#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number3.in","r",stdin);
	freopen("number3.ans","w",stdout);
	string s;
	int sz[1005],count=0;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			sz[count++]=s[i]-48;
		}
	}
	sort(sz,sz+count);
	for(int i=count-1;i>=0;i--){
		if(sz[count-1]!=0){
			cout<<sz[i];
		}else{
			cout<<0<<endl;
			break;
		}
	}
	return 0;
}
