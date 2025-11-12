#include<bits/stdc++.h>
using namespace std;
string s;
int n,m;
int a[1000100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++m]=int(s[i]-'0');
		}
	}
	sort(a+1,a+m+1);
	if(a[m]==0){
		printf("0");
		return 0;
	}
	for(int i=m;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
} 
