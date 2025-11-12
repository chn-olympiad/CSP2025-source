#include<bits/stdc++.h>
using namespace std;
string a;
int aa[1000005],sum=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.size();i++){
		int ss=int(a[i]);
	//	cout<<ss<<endl;
		if(ss>=48&&ss<=57){
			aa[sum]=a[i]-'0';
		//	cout<<a[i]-'0'<<endl;
			sum++;
		}
	}
	sort(aa+1,aa+sum);
	for(int i=sum-1;i>=1;i--){
		cout<<aa[i]; 
	}
	return 0;
}
