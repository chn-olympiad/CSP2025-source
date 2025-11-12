#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	string a,b;
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9') b+=a[i];
	}
	sort(b.begin(),b.end());
	if(b[b.size()-1]=='0'){
		cout<<0;
		return 0;
	}
	for(int i=b.size()-1;i>=0;i--){
		cout<<b[i];
	}
	cout<<endl;
	return 0;         
}
