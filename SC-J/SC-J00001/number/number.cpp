#include<bits/stdc++.h>
using namespace std;
string c;
int a[1000009],sum=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	for(int i=0;i<int(c.size());i++){
		if(c[i]>='0'&&c[i]<='9'){
			a[sum]=c[i]-'0';
			sum++;
		}
	}
	sum--;
	sort(a+1,a+sum+1);
	for(int i=1;i<=sum;i++){
		cout<<a[sum-i+1];
	}
	return 0;
}