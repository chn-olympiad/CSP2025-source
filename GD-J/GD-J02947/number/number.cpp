#include<bits/stdc++.h>
using namespace std;

int num[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	int k=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')
		num[k++]=s[i]-'0';
	}
	sort(num,num+k,cmp);
	for(int i=0;i<k;i++){
		cout<<num[i];
	}
	return 0;
}
