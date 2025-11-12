#include<bits/stdc++.h>

using namespace std;
int a[500011];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int j=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-48;
			j++;
		}
	}
	int m=j;
	sort(a,a+m);
	reverse(a,a+m);
	for(j=0;j<m;j++){
		cout<<a[j];
	}
	return 0;
}
