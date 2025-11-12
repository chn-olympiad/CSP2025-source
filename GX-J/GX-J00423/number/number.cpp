#include <bits/stdc++.h>
using namespace std;
bool x(char s){
	if(int(s)-48<49&&int(s)-48>0)return true;
	else return false;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	string s;cin>>s;
	long a[s.length()],n=0;
	for(int i=0;i<int(s.size());i++){
		if (x(char(s[i]))){a[i]=int(s[i])-48;n+=1;}
		else{
			continue;
			}
	}
	sort(a,a+n);
	int i=n-1;
	while(1){
		if(i<0){
			break;
		}
		cout<<a[i];
		i--;
	}
	return 0;
}
