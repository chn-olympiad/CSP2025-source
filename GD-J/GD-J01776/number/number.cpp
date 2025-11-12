#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[100010];
	int cnt=0,num=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	for(int i=0;i<cnt;i++){
		int m=0,o=0;
		for(int j=i;j<cnt;j++){
			if(a[j]>m){
				m=a[j];
				o=j;
			}
		}
		int n=a[i];
		a[i]=a[o];
		a[o]=n;
		num=num*10+a[i];
	}
	cout<<num<<endl;
	return 0;
} 
