#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[10]={0};
	bool flag=false;
	string s;
	cin>>s;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]==0) continue;
		else{
			if(i==0&&!flag){
				cout<<0;
			}
			else{
				while(a[i]--) cout<<i;
				flag=true;
			}
		}
	}
	return 0;
}
