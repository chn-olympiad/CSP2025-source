#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000001];

int main(){
	freopen("number.in","r",stdin);
  	freopen("number.out","w",stdout);
	cin>>s;
	int t=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='3'||s[i]=='2'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			++t;
			a[t]=s[i]-'0';
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=i;j<=t;j++){
			if(a[j]>a[i]){
				int dog=a[j];
				a[j]=a[i];
				a[i]=dog;
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<a[i];
	}
	return 0;
}
