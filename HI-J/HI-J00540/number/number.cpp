#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int c=0,d[1005],e=0;
	string s;
	cin>>s;
	for(int i=0;i<=int(s.size())-1;i++){
	if(s[i]>='0'&&s[i]<='9'){
		d[c]=int(s[i]-'0');
		c++;
	}
	}
	int a=c-1;
	for(int i=0;i<=c;i++){
		for(int j=0;j<=a;j++){
			if(d[j]>d[j+1]){
				int b=d[j];
				d[j]=d[j+1];
				d[j+1]=b;
			}
		}
	}	
	for(int i=c-1;i>=0;i--){
		e+=d[i]*pow(10,i);
	}
	cout<<e;
	return 0;
}
