#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],k=0;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a,a+k,cmp);
	for(long long i=0;i<k;i++){
		cout<<a[i];
	}
	return 0;
} 