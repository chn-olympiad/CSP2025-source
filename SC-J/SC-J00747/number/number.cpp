#include<bits/stdc++.h>
using namespace std;
string s; 
int a[1000005],p=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[i]=s[i]-'0'+1;
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--){
		if(a[i]!=0){
			cout<<a[i]-1;
		}
	}
	return 0;
}