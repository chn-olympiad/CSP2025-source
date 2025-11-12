#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a > b;
}
string s;
int num[1000002];
int sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	for(int i = 0;i < s.length(); i++){
		if(char(s[i]) > 47 && char(s[i]) < 58){
			sum++;
			num[sum] = char(s[i]) - 48;
		}
	}sort(num + 1,num + 1+sum,cmp );
	for(int i = 1;i<=sum;i++)printf("%d",num[i]);
	return 0; 
}
