	#include<bits/stdc++.h>
	using namespace std;
	long long N=1000000;
	int main(){
	freopen("number.in"," s[N]",stdin);
	freopen("number.out","b[N]",stdout);
	char s[N]={};
	cin>>s[N];
	for(int i=1;i<=N;i++){
	if(s[i]<s[i+1]){
		s[i]=s[i+1];
	}}
	char a[N],b[N];
	for(int i=1;i<=N;i++){
		if(int(s[i])>=65){
		a[i]=s[i];
		}
		else{
			b[i]=a[i];
		}
}
	for(int i=1;i<=N;i++){
		if(b[i]<b[i+1]){
			b[i]=b[i+1];
		}
	}
	for(int i=1;i<=N;i++){
		cout<<b[i]<<endl;
	}
	return 0;
}

