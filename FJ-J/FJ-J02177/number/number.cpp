#include<bits/stdc++.h>
using namespace std;
string s;
long long arr[1000010],sum=0;
long long cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	cin>>s;
	long long a=s.size();
	for(int i=0 ; i<a ; i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum++;
			arr[sum]=s[i]-'0';
		}
	}
	sort(arr+1,arr+1+sum,cmp);
	for(int i=1 ; i<=sum ; i++){
		cout<<arr[i];
	}
	return 0;
}
