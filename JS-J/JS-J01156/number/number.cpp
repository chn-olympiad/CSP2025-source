#include<bits/stdc++.h>
using namespace std;
int j;
string s;
char a[1000005];
bool cmp(char x,char y){
		return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lo=s.size();
	for(int i=0; i<lo; i++){
		if(s[i]>='0'&&s[i]<='9'){  
			a[j]=s[i];
			j++;
		}
	}
	string ans="";
	sort(a,a+j,cmp); 
	for(int i=0; i<j; i++){
		ans=ans+a[i];
	}
	cout<<ans;
	return 0;
}
