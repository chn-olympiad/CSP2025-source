#include<bits/stdc++.h>
using namespace std;
string n;
int a[1000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int cmp1=0;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0' && n[i]<='9'){
			a[cmp1]=n[i]-'0';
			cmp1++;
		}
	}
	sort(a,a+cmp1);
	for(int i=0;i<cmp1;i++){
		printf("%d",a[cmp1-i-1]);
	}
	return 0;
}