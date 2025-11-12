#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
string s;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[sum]=s[i];
			sum++;
		}
	}
	sort(a,a+sum,cmp);
	for(int i=0;i<sum;i++){
		cout<<char(a[i]);
	}
	return 0;
} 
