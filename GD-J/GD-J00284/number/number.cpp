#include<bits/stdc++.h>
using namespace std;
string a;
int s[1000100],k;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			k++;
			s[k]=a[i]-'0';
		}
	}
	sort(s+1,s+k+1,cmp);
	for(int i=1;i<=k;i++){
		cout<<s[i];
	}
}
