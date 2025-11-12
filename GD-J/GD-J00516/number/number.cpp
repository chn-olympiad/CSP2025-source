#include<bits/stdc++.h>
using namespace std;
string s;
int mymax=-999999,d=0;
char a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			d++;
			a[d]=s[i];
		}	
	}	
	sort(a,a+d+1);
	for(int i=d;i>=0;i--){
		cout<<a[i];
	}
	
	
	
	
	
	return 0;
}
