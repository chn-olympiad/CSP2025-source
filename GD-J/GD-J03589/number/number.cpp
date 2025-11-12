#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n = s.size()-1,cnt = 0;
	for(int i = 0;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	}
	for(int i = 9;i>=0;i--){
		if(a[i]!=0){
			for(int j = 1;j<=a[i];j++)
				printf("%d",i);
		}
	}
	return 0;
} 
