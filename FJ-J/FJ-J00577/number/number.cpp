#include<bits/stdc++.h>
using namespace std;
int num[1000005];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in",'r',stdin);
	freopen("number.out",'w',stdout);
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			num[j]=s[i]-'0';
			j++;
		}
	}
	sort(num+0,num+j,cmp);
	for(int i=0;i<j;i++){
		cout<<num[i];
	}
	return 0;
}
