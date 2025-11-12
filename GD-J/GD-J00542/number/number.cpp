#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
	string s;
	cin>>s;
	int num=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num++;
			a[num]=(s[i]-'0');
		}
	}
	sort(a+1,a+1+num);
	int o=0;
	for(int i=num;i>=1;i--){
		if(o==0&&a[i]==0){
			if(i==num){
				cout<<0;
				return 0;
			}
		}else{
			o=1;
			cout<<a[i];
		}
	}
	return 0;
}
