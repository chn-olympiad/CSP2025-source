#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int num=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
			num++;
		}
	}
	int i=9;
	while(num&&i>=0){
		if(a[i]!=0)
			for(int j=0;j<a[i];j++){
				cout<<i;
				num--;
			}
		i--;
	}
	return 0;
}
