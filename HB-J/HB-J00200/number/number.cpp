#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int sum;
bool check(int x,int y){
	if(x>y){
		return true;
	}
	else{
		return false;
	}
}
int main(){   
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin >>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[sum]=s[i]-'0';
			sum++;
		}
	}
	sort(a,a+sum,check);
	for(int i=0;i<sum;i++){
		cout <<a[i];
	}
}
