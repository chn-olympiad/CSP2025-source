#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int p=0,i;
string s;
int num[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[p]=s[i]-'0';
			p++;
		}
	}
	sort(num,num+p,cmp);
	for(i=0;i<p;i++){
		cout<<num[i];
	}
	return 0;
} 
