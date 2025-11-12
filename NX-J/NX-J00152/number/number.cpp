#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",cin);
	freopen("number.out","w",cout);
	string s;
	cin>>s;
	int a=s.size();
	int o=0;
	int y[a]={0};
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			y[o]=(s[i]-'0');
			o++;
		}
	}
	sort(y,y+o);
	for(int i=o-1;i>=0;i--){
		cout<<y[i];
	}
	
	
}
