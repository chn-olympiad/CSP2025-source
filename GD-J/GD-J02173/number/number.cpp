#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n,m,k=0;
	char a[1000000];
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i];
			k++;
		}
	}
	for(int i=0;i<k-1;i++){
		for(int j=i;j<k-1;j++){
			if(a[j]<a[j+1]){
				m=a[j];
				a[j]=a[j+1];
				a[j+1]=m;
			}
		}
	}
	for(int i=0;i<k;i++){
		cout<<a[i];
	}
	return 0;
} 
