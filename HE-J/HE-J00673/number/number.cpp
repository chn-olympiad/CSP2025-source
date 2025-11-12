#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[999999],a[999999];
	long long m=0,n;
	cin>>s;
	for(int i=1;;i++){
		if(s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9'){
			
		}else{
			n=i;
			break;
		}
	}
	for(long long i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[m]=s[i];
			m++;
		}
	}
	for(long long i=0;i<=m;i++){
		for(long long j=0;j<=m;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(long long i=0;i<=m;i++){
		cout<<a[i];
	}
	return 0;
}
