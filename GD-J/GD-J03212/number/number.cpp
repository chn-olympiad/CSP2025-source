#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j;
	int a[1000000],n=s.length();
	for(int i=0;i<n-1;i++) {
		if(s[i]>='0'){
			if(s[i]<='9') {
				a[j]=s[i]-'0';
				j++;
				}
			}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<j;i++) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
}
