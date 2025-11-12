#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long p[N],num = 0;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long len = s.length();
	for(int i = 0;i <= len+1;i++){
		if(s[i] == '0')p[i+1] = 0,num++;
		if(s[i] == '1')p[i+1] = 1,num++;
		if(s[i] == '2')p[i+1] = 2,num++;
		if(s[i] == '3')p[i+1] = 3,num++;
		if(s[i] == '4')p[i+1] = 4,num++;
		if(s[i] == '5')p[i+1] = 5,num++;
		if(s[i] == '6')p[i+1] = 6,num++;
		if(s[i] == '7')p[i+1] = 7,num++;
		if(s[i] == '8')p[i+1] = 8,num++;
		if(s[i] == '9')p[i+1] = 9,num++;
	}
	sort(p,p+len+1,cmp);
	for(int i = 0;i < num;i++){
		cout<<p[i];
	}
	return 0;
}
