#include<bits/stdc++.h>
using namespace std;
int nm[1000005];
int cp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;int k=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			
		nm[k]=int(a[i]-'0');
		k++;
		}

	}
			sort(nm,nm+k,cp);
		for(int i=0;i<k;i++)cout<<nm[i];
	return 0;
}
