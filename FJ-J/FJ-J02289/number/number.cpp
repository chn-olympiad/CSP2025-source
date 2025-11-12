#include<bits/stdc++.h>
using namespace std;
int b[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int sum=0;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>='0' && a[i]<='9'){
			b[sum++]=a[i]-'0';
		}
	}
	sort(b,b+sum);
	for(int i=sum-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
