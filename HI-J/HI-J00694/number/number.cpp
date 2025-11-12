#include<bits/stdc++.h>
using namespace std;
int a[1000001],k=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			a[k+1]=s[i]-48;
			k++;
		}
	}
	if(k==1){
		cout<<a[1];
		return 0;
	}
	for(int i=1;i<=k;i++){
		int flag=0;
		for(int j=1;j<=k-1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
				flag=1;
			}
		}
		if(flag==0) break;
	}
	for(int i=1;i<=k;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
