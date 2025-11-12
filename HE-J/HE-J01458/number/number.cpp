#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long n=a.size();
    long long b[n];
	int x=0;
	for(int i=0;i<n;i++){
		if(a[i]>='0' && a[i]<='9'){
			long long qqq=a[i]-'0';
			
			b[x]=qqq;
			x++;
		}
	}
	sort(b,b+x);
	
	for(int i=x-1;i>=0;i--){
		cout<<b[i];
	}
	
	return 0;
} 
