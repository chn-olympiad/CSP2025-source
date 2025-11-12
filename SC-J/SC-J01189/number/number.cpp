#include<bits/stdc++.h> 
using namespace std;
const int maxn=1e6+5;
long long a[maxn],b[maxn],num=0;
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[i]=s[i];
		a[i]-=48;
		if(a[i]>=0 && a[i]<=9){
			b[num]=a[i];
			num++;
		}
	}
	sort(b,b+num);
	for(int i=num-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}