#include<bits/stdc++.h>
using namespace std;
const int N=1000005;

string n;
char a[N];

bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>n;
	
	int o=0;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[++o]=n[i];
		}
	}
	sort(a+1,a+1+o,cmp);
	
	for(int i=1;i<=o;i++){
		cout<<a[i];
	}
	
	return 0;
}
