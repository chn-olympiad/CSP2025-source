#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int ns=0;
	int n[10005];
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			ns++;
			n[ns]=a[i]-'0';
		}
	}
	for(int i=1;i<=ns;i++){
		int max1=-1,in;
		for(int j=1;j<=ns;j++){
			if(max1<n[j]){
				max1=n[j];
				in=j;
			}
		}
		cout<<max1;
		n[in]=-1;
	}
	return 0;
} 
