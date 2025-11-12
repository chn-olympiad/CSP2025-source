#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	int n=1;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
