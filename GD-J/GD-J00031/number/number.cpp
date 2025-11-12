#include<bits/stdc++.h>
using namespace std;
string s;
int ts=0,a[1000003],st;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	getline(cin,s);
	int n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			ts++;
			a[ts]=s[i]-48;
		}
	sort(a+1,a+n+1,cmp);
	if(a[1]==0){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=ts;i++)
		cout<<a[i];
	return 0;
} 
