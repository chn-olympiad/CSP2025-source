#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size()-1,cnt=0;
	for(int i=0;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i+1]=int(s[i]-'0');
			cnt++;
		}
	} 
	sort(a+1,a+n+2,cmp);
	for(int i=1;i<=cnt;i++)
		cout<<a[i];
	return 0;
} 
