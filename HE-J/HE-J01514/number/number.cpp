#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a=s.size(),j=0;
	int b[a];
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[j]=s[i];
			j++;
		}
	}
	
	for(int i=0;i<a-1;i++){
		for(int j=i+1;j<a;j++){
			b[i]=max(b[i],b[j]);
		}
	}
	cout<<b;
	return 0;
	
}
