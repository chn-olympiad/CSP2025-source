#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a,int b){
	if(a<b){
		return 0;
	}
	return 1;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	int top = 0;
	for(int i = 0;i<str.size();i++){
		if(str[i] >= '0'&&str[i]<='9'){
			top++;
			a[top] = str[i] - '0';
		}
	}
	top--;
	sort(a+1,a+top+1,cmp);
	for(int i = 1;i<=top;i++){
		cout<<a[i];
	}
}
