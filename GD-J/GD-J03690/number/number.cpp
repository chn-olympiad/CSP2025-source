#include<bits/stdc++.h>
using namespace std;
string a;
int numm[1000005];
int n=0,ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			numm[++n]=a[i]-'0';
		}
	}
	sort(numm+1,numm+n+1);
	for(int i=n;i>=1;i--){
		cout<<numm[i];
	}
	cout<<endl;
	
	return 0;
}
