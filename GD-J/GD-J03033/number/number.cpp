#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a;
	int b=0;
	int ss=s.size();
	int list[ss+100];
	for(int i=0;i<ss;i++){
		if(s[i]-48<10){
			list[b]=s[i]-48;
			b++;
		}
	}
	for(int i=0;i<b;i++){
		for(int j=0;j<b;j++){
			if(list[j]<list[i]){
				a=list[j];
				list[j]=list[i];
				list[i]=a;
			}
		}
	}
	for(int i=0;i<b;i++){
		cout<<list[i];
	}
	fclose(stdin);
	fclose(stdout);
} 
