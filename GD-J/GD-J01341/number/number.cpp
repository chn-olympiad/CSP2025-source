#include<bits/stdc++.h>
using namespace std;
long long a[1000055],ai,n;
string s;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9') a[ai++]=s[i]-'0';
	} sort(a,a+ai,cmp);
	for(int i=0;i<ai;i++){
		cout<<a[i];
	}
	return 0;
} 
