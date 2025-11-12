#include<bits/stdc++.h> 
using namespace std;
string a;
long long n;
int main{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>a;
	n=a.size();
	for(int i=0;i<=n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			if(a[i]>a[i-1]){
				a[i]=a[i-1];
		}
	}		
	if(a[i]>=97&&a[i]<=122){
		erase(a[i]);
	}
	}
	for(int i=0;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}
