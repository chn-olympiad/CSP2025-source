#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],j=0;
string s;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			j++;
			a[j]=s[i]-'0';
		}
	}
	sort(a+1,a+1+j,cmp);
	for(int i=j;i>=1;i--)cout<<a[i];
	return 0;
}
