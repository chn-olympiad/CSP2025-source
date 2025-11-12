#include<bits/stdc++.h>
using namespace std;
int a[15];
string s;
bool flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;	
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			if(i!=0)flag=1;
			else if(!flag){
				cout<<0;
				return 0;
			} 
			printf("%d",i);
			a[i]--;
		}
	}
	return 0;
}
