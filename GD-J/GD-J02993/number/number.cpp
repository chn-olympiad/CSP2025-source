#include<bits/stdc++.h>
using namespace std;
int arr[1000005],temp[1000005];
string s;
void merge(long long ls,long long le,long long rs,long long re){
	int x=ls,flag=ls;
	while(ls<=le&&rs<=re){
		if(arr[ls]<arr[rs]) temp[x++]=arr[rs++];
		else temp[x++]=arr[ls++];
	}
	while(ls<=le) temp[x++]=arr[ls++];
	while(rs<=re) temp[x++]=arr[rs++];
	for(int i = flag;i<=re;i++) arr[i]=temp[i];
}
void sort_merge(long long l,long long r){
	if(l<r){
		int mid=(l+r)/2;
		sort_merge(l,mid);
		sort_merge(mid+1,r);
		merge(l,mid,mid+1,r);
	}
}
int main(){
	long long f=1;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
		 	arr[f]=s[i]-'0';
		 	f++; 
		} 
	}
	
	sort_merge(1,f+1);
	for(int i = 1;i<f;i++) cout << arr[i];
	return 0;
}
