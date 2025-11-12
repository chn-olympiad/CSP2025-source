#include<bits/stdc++.h>
using namespace std;
const int mn=1e6+10;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	char a[mn];
	int n=0;
	int len=s.size();
	for(int i=1;i<=len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			n++;
			a[n]=s[i];
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i]; 
	}
	return 0;
} 
