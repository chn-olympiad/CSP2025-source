#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int num[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int step=1;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[step]=s[i]-'0';
			step++;
		}
	}
	step--;
	sort(num+1,num+step+1,cmp);
	for(int i=1;i<=step;i++)cout<<num[i];
	return 0;
}
