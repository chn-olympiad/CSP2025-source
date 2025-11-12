#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length();
	int sum=0;
	int num[1000001]={0};
	for(int i=0;i<n;i++){
		int a=s[i];
		if(a>=48&&a<=57){
			sum++;
			num[sum]=a-48;
		}
	}
	sort(num+1,num+sum+1,cmp);
	if(num[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=sum;i++){
		cout<<num[i];
	}
	return 0;
}
