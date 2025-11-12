#include<bits/stdc++.h>

using namespace std;
int a[1000010];
int t=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[++t]=n[i]-'0';
		}
	}
	sort(a+1,a+1+t);
	for(int i=t;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
