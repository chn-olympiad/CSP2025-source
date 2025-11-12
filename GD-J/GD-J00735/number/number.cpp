#include<bits/stdc++.h>
using namespace std;
string s;
char ss[1000005];
bool f=true;
int a[1000005];
int t; 
bool check(char sb){
	if(sb-'0'>=0&&sb-'0'<=9)return true;
	else return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(check(s[i])){
			ss[t]=s[i];
			t++;
		}
	}
	for(int i=0;i<t;i++)a[i]=int(ss[i]-'0');
	sort(a,a+t);
	for(int i=t-1;i>=0;i--)cout<<a[i];
	cout<<endl;
	return 0;
} 
