#include <bits/stdc++.h>
using namespace std;
int n[1000001]={0};
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	 
	string a;
	cin>>a;
	
	int sum=0;
	
	
	for(int i=0 ; i<a.size();i++){
		if('0'<=a[i] && a[i]<='9'){
			if(a[i]=='0'){
				n[sum]=0;
				sum++;
			}
			if(a[i]=='1'){
				n[sum]=1;
				sum++;
			}
			if(a[i]=='2'){
				n[sum]=2;
				sum++;
			}
			if(a[i]=='3'){
				n[sum]=3;
				sum++;
			}
			if(a[i]=='4'){
				n[sum]=4;
				sum++;
			}
			if(a[i]=='5'){
				n[sum]=5;
				sum++;
			}
			if(a[i]=='6'){
				n[sum]=6;
				sum++;
			}
			if(a[i]=='7'){
				n[sum]=7;
				sum++;
			}
			if(a[i]=='8'){
				n[sum]=8;
				sum++;
			}
			if(a[i]=='9'){
				n[sum]=9;
				sum++;
			}
		}
		
	}
	
	sort(n,n+sum);
	
	
	for(int i=sum-1 ; i>=0 ; i--){
		cout<<n[i];
	}
	
	return 0;
} 
