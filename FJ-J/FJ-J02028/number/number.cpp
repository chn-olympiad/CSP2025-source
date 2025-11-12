#include<bits/stdc++.h>
using namespace std;
string s;
long long a[11],l;
bool t=false;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;++i){
		if(s[i]>='0'&&s[i]<='9'){
			++a[int(s[i]-'0')%10];
//			cout<<int(s[i]-'0')%10;
		}
	}for(int i=9;i>0;--i){
		if(a[i]>0){
			t=true;
			for(int j=1;j<=a[i];++j){
				cout<<i;
			}
		}
	}if(!t){
		cout<<0;
	}else{
		for(int j=1;j<=a[0];++j){
			cout<<0;
		}
	}
	return 0;
}
