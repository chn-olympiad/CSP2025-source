#include<bits/stdc++.h>
using namespace std;
long long a,b,y,su=0;
string x;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	cin>>x;
	for (int i=0;i<a;i++){
		cin>>y;
		if (y==0){
			su++;
		}
	}
	if (b+su>a){
		cout<<0;
		return 0;
	}
	long long sum=1;
	for (int i=1;i<=a;i++){
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdin);
	return 0;
} 
