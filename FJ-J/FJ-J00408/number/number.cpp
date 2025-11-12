#include<bits/stdc++.h>
using namespace std;
string s;
int num[100100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=1;
	for(int i=0;i<=s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			num[j]=s[i]-'0';
			j++;
		}
	}
	sort(num+1,num+j+1,cmp);
	for(int i=1;i<j;i++){
		cout<<num[i];
	}
	return 0;
}
