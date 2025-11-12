#include<bits/stdc++.h>
using namespace std;
string a;
long long ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long num=a.length();
	for(long long i=0;i<num;i++) if(a[i]>='0'&&a[i]<='9') ans++;
	long long b[num];
	for(long long i=0;i<num;i++) b[i]=-1;
	for(long long i=0;i<num;i++) if(a[i]>='0'&&a[i]<='9') b[i]=a[i]-48;
	sort(b,b+num);
	for(long long i=num-1;i>=0;i--) if(b[i]>=0) cout<<b[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
