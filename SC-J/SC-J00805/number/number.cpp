#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000002],j=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]<='9' && s[i]>='0'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=j-1;++i){
		cout<<a[i];
	}
	return 0;
}