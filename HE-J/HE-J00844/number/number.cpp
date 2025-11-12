#include<bits/stdc++.h>
using namespace std;
int main(){
	string n;
	int a[1000005]={0},j=1;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>=48&&n[i]<=57){
			a[j]=int(n[i])-48;
			j++;
		}
	}
	sort(a+1,a+j+1);
	for(;j>=1;j--){
		cout<<a[j];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
