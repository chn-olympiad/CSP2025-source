#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int sum=0;
	cin>>s;
	for(int i=0;i<int(s.size());i++){
		if(isdigit(s[i])){ 
			sum++;
			a[sum]=(s[i]-'0');
		}
	}
	sort(a+1,a+sum+1,greater<int>());
	for(int i=1;i<=sum;i++) cout<<a[i];
	return 0;
}
