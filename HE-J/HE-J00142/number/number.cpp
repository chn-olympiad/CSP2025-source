#include<bits/stdc++.h>
using namespace std;
string n;
int a[1000001],j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[j]=n[i]-'0';
			j++;
		}
	}
	sort(a+0,a+j);
	while(j--){
		cout<<a[j];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
