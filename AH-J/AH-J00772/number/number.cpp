#include<bits/stdc++.h>
using namespace std;
char a[10000001];
int main(){
	//freopen("number.in","w",stdin);
	//freopen("number.out","r",stdout);
	string s,st;
	cin>>s;
	long long k=s.length(),j=1,d=1;
	for(long long i=0;i<k;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[j]=s[i];
			j++;
		} 
	}
	for(long long i=1;i<=k;i++){
		for(long long i=1;i<=k;i++){
			long long t;
			if(a[i]<a[i+1]){
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			} 
		}
	}
	for(long long i=1;i<=k;i++){
		if(i==d && a[i]=='0') d++;
		else st+=a[i]; 
	}
	if(d-1==k) cout<<0;
	else cout<<st;
	return 0;
}
