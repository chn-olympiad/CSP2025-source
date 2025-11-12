#include<bits/stdc++.h>
using namespace std;
long long a[10000000]={0};
bool cnt(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=1;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a+1,a+n,cnt);
	for(int i=1;i<=n-1;i++){
		cout<<a[i];
	}
} 
