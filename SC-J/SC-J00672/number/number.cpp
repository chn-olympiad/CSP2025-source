#include<bits/stdc++.h>
using namespace std;
int a[1000005],j=1;string m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[j]=n[i]-'0';
			//m=m+n[i];
			j++;
		}
	}
	j--;
	sort(a+1,a+j+1);
	for(int i=j;i>=1;i--){
		cout<<a[i];
	}
	//cout<<m;
	return 0;
}