#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],a1=0; 
int cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a1++;
			a[a1]=s[i]-'0';
		}
	}
	sort(a+1,a+a1+1,cmp);
	for(int i=1;i<=a1;i++)cout<<a[i];
	return 0;
} 
