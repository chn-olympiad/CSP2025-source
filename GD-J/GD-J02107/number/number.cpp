#include<bits/stdc++.h>
#include<string>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int se=s.size();
	int o=0;
	for(int i=0;i<se;i++){
		if(s[i]-'0'<10&&s[i]-'0'>=0){
			a[++o]=s[i]-'0';
		} 
	}
	for(int i=1;i<=o;i++){
		for(int j=i+1;j<=o;j++){
			if(a[i]<a[j])swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=o;i++){
		cout<<a[i]; 
	}
	return 0;
}
