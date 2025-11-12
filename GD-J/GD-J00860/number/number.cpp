#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],l=0,num=0;
bool kp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]-'0'<=9&&s[i]-'0'>=0) {
			a[i]=s[i]-'0';
			num++;
		}
	}
	sort(a,a+l,kp);
	for(int i=0;i<num;i++) cout<<a[i];
	return 0;
} 
