#include<bits/stdc++.h>
using namespace std;
string s,jg;
int a[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=1;
	for(int i=0;i<s.size();i++){
		if(s[i]-'9'<=0&&s[i]-'0'>=0){
			a[l]=s[i];
			l++;
		}
	}
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<l;i++){
		jg+=a[i];
	}
	cout<<jg;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
