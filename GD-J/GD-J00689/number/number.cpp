#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int num[1919810];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	char ch;
	int po=0;
	while(cin>>ch){
		if(ch>='0' && ch<='9'){
			num[po]=ch-'0';
			po++;
		}
		
	}
	sort(num,num+po,cmp);
	for(int i=0;i<po;i++){
		cout<<num[i];
	}
	return 0;
}
