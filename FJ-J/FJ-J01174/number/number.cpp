#include<bits/stdc++.h>
using namespace std;
string s;
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x;
			x=int(s[i]-'0');
			a[x]++;
		}
	}
	bool f=false;
	for(int i=9;i>=0;i--){
		if(a[i]==0) continue;
		if(a[i]!=0&&i!=0) f=true;
		if(f==false&&i==0){
			printf("0");
			return 0;
		}
		for(int j=1;j<=a[i];j++){
			printf("%d",i);	
		}
	}
	return 0;
} 
