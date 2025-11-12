#include<bits/stdc++.h>
using namespace std;
int a[1000003];
bool cmp(int i,int j){
	return i>j;
}
int main(){
	int i,n,cnt=0;
	string s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(i=0;i<n;i++){
		//cout<<s[i];
		if(s[i]>='0' && s[i]<='9'){
			cnt++;
			//cout<<s[i];
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
