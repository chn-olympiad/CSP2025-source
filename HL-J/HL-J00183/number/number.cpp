#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int num[N];
int j=0;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			num[j]=s[i]-'0';
			j++;
		}
	}
	sort(num,num+j,cmp);
	for(int i=0;i<=j-1;i++){
		cout<<num[i];
	}
	return 0;
}
