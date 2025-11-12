#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	int m=0;
	for(int i=0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			m+=1;
			a[m]=s[i]-'0';
		} 
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		cout<<a[i];
	}
	return 0;
} 
