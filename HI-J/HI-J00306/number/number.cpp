#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
long long j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>s; 
	for(int i=0;i<=s.size();i++){
			a[j]=s[i];
			j++;
	}
	sort(a,a+j);
	for(int i=j-1;i>=1;i--){
		if(a[i]<97){
			cout<<char(a[i]);
		}
	}
	return 0;
}

