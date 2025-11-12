#include<bits/stdc++.h>
using namespace std;
string n;
int a[1000001],pos=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[pos++]=n[i]-'0';
		}
	}
	sort(a+1,a+pos);
	for(int i=pos-1;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
