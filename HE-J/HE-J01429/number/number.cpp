#include<bits/stdc++.h>
using namespace std;
char s[100000000];
long long a[10000000],b=0,q;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
cin>>s;
for(long long i=0;i<sizeof(s);i++){
	if (s[i]>='0'&&s[i]<='9'){
		a[b]=s[i]-48;
		b++;
	}
}
for(long long i=0;i<=b;i++){
	for(long long j=0;j<=i;j++){
		if(a[j]<a[j+1]){
			q=a[j];
			a[j]=a[j+1];
			a[j+1]=q;
		}
	}
}
for(long long i=0;i<b;i++){
	cout<<a[i];
}
cout<<endl;

	return 0;
}
