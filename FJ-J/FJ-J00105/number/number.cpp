#include<bits/stdc++.h>
using namespace std;
string n;
long long a[1000000],sum;
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]-'0'>=0&&n[i]-'0'<=9){
			a[i+1]=n[i]-'0';
			sum++;
		}
	}
	sort(a+1,a+n.size()+1,cmp);
	for(int i=1;i<=sum;i++){
		cout<<a[i];
	}
	return 0;
}
