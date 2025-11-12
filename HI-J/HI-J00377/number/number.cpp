#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1,s2;
	cin>>s1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9')s2=s2+s1[i];
	}
	int q=0,w=0;
	for(int i=0;i<s2.size();i++){
		if(s2[i+1]>s2[i]){
			w=s2[i];
			s2[i]=s2[i+1];
			s2[i+1]=w;
			q++;
		}
		if(q!=0){
			i=0;
			q=0;
		}
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i+1]>s2[i]){
			w=s2[i];
			s2[i]=s2[i+1];
			s2[i+1]=w;
			q++;
		}
	} 
	int a=0;
	for(int i=0;i<s2.size();i++){
		a=a*10+(s2[i]-'0');
	}
	cout<<a;
	return 0;
}
