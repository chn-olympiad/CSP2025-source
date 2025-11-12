#include<bits/stdc++.h>
using namespace std;
string a;
long long s,x[1000009],n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long w=a.size();
	for(int i=0;i<=w;i++){
		s=a[i];
		if(s>=49&&s<=57){
			n++;
			x[n]=s-48;
		}
	}
	sort(x+1,x+n+1);
	for(int i=n;i>=1;i--){
		cout<<x[i];
	}
	return 0;
}
