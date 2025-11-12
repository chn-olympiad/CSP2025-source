#include<bits/stdc++.h>
using namespace std;
string a;
int tot=0,num[100001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int l=a.length()-1;
	for(int i=0;i<=l;i++){
		if(a[i]>='0'&&a[i]<='9'){
			tot++;
			num[tot]=int(a[i]-48);
		}
	}
	sort(num+1,num+tot+1);
	for(int i=tot;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}