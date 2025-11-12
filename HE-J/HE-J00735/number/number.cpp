#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string str;
int a[N],ai;
bool cmp(int xx,int yy){
	return xx>yy;
}
int main(){

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>str;
	int n=str.length();
	for(int i=0;i<n;i++){
		if(str[i]>='0'&&str[i]<='9'){
			ai++;
			a[ai]=str[i]-'0';
		}
	}
	sort(a+1,a+ai+1,cmp);
	for(int i=1;i<=ai;i++){
		cout<<a[i];
	}
	
	return 0;
}

