#include <bits/stdc++.h>
using namespace std;
const int Maxn=1e7+10;
int n[Maxn]; 
int nums=0; 
bool compare(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0' && a[i]<='9'){
			n[nums]=a[i]-'0';
			nums++;
		}
	}
	sort(n,n+nums,compare);
	for(int i=0;i<nums;i++){
		cout<<n[i];
	}
	return 0;
} 
