#include<bits/stdc++.h>
using namespace std;
int a[1000005];
long long ans;
string s,b;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j,cmp);
	for(int i=1;i<=j-1;i++){
		cout<<a[i];
	}
	return 0;
} 
