#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000022],n;
bool bj(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n,bj);
	for(int i=0;i<n;i++) cout<<a[i];
	return 0;
} 
