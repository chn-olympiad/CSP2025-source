#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[100005];
	int m=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[m]=s[i]-'0';
			m++;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<i;j++){
			if(a[j]<a[i]){
				int n=a[j];
				a[j]=a[i];
				a[i]=n;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<a[i];
	}
	return 0;
} 
