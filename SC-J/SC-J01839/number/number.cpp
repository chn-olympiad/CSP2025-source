#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	int j=1;
	for(int i=0;i<l;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[j]=s[i]-48;
			j++;
		}
	}
	sort(a+1,a+1+j,cmp);
	for(int i=1;i<j;i++){
		cout<<a[i];
	}
	return 0;
} 