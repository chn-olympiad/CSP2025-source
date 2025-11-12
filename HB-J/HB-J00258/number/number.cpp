#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int js=n.length(),m=0;
	int a[js];
	for(int i=0;i<js;i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[m]=n[i]-'0';
			m++;
		}
	}
	sort(a,a+m,cmp);
	for(int i=0;i<m;i++){
		cout<<a[i];
	}
}
