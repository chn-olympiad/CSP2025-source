#include<bits/stdc++.h>
using namespace std;
string n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	long long a[n.size()+1],j=0;
	for(int i=0;i<n.size();i++){
		if(n[i]<='9'&&n[i]>='0'){
			a[j]=n[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--)cout<<a[i];
	return 0;
}