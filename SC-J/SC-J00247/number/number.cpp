#include <bits/stdc++.h>
using namespace std;
string n;
int a[1000005];
long long sum;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=0;i<n.size();i++){
		if(n[i]-'0'>=0 and n[i]-'0'<=9){
			a[sum]=n[i]-'0';
			sum++;
		}
	}
	sort(a,a+sum,cmp);
	for(long long i=0;i<sum;i++){
		cout<<a[i]; 
	}
	return 0;
} 