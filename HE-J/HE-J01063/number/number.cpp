#include<bits/stdc++.h>
using namespace std;
string str;
int a[9];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]>='0'&&str[i]<='9'){
			a[str[i]-'0']++;
		}			
	}
	if(a[0]>0&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0&&a[7]==0&&a[8]==0&&a[9]==0){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)cout<<i;
	}
	return 0;
}
