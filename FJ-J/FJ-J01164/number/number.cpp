#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[1000005];
	string n;
	cin>>n;
	int k=0;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
		a[k]=n[i]-'0';
			k++;	
		}
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;--i){
		cout<<a[i];
	}
	return 0;
}
