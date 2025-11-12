#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,b;
	cin>>s;
	int a=s.size();
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b+=s[i];
		}
	}
	for(int i=0;i<a;i++){
		for(int j=i;j<a;j++){
			if(b[j]>b[i]){
				char t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
	} 
	cout<<b;
	return 0;
}
