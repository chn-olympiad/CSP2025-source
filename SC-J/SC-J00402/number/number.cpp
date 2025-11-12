#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;int a[110000];
	int k = s.size();//cout<<k;
	int j = 0;
	for(int i = 0;i<k;i++){
		if(s[i]-48>=0 &&s[i]-48<=9){
			a[j] = s[i]-48;
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i = 0;i<j;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 