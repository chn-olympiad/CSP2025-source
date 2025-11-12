#include<bits/stdc++.h>
using namespace std;
	int aa[11]={0};
	string a;
int main(){
	freopen("number4.in","r",stdin);
	freopen("number4.out","w",stdout);
	cin>>a;
	//cout<<a<<" "<<a<<"\n";
	int b=a.size();
	for(int i=0;i<b;i++){
		if(a[i]>='0'&&a[i]<='9')
		aa[a[i]-'0']++;
	}
	//cout<<aa[5]<<"\n";
	for(int i=9;i>=0;i--){
		for(int o=1;o<=aa[i];o++){
		cout<<i;
		}
	}
	return 0;
} 
