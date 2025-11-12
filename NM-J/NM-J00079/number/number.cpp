#include<bits/stdc++.h>
using namespace std;
string st;
int a[100010],lkg,k[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	int len1=st.size();
	for(int i=0;i<len1;i++){
		if(st[i]>='0'&&st[i]<='9'){
			lkg++;
			a[lkg]=int(st[i]-'0');
		}
	}
	for(int i=1;i<=lkg;i++){
		k[a[i]]++;
	}
	for(int i=9;i>=0;i--){
		if(k[i]>0){
			for(int j=k[i];j>=1;j--){
				cout<<i;
		}
		}
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
