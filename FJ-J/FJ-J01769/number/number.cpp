#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000000+5],k,tmp[1000000+5];
void merge(long long L,long long mid,long long R){
	long long i=L,m=L,j=mid+1;
	while(i<=mid&&j<=R){
		if(a[i]<a[j]) tmp[m++]=a[i++];
		else tmp[m++]=a[j++];
	}
	while(i<=mid){
		tmp[m++]=a[i++];
	}
	while(j<=R){
		tmp[m++]=a[j++];
	}
	for(long long g=L;g<=R;g++){
		a[g]=tmp[g];
	}
}
void mergeSort(long long L,long long R){
	if(L>=R) return;
	long long mid=(R+L)/2;
	mergeSort(L,mid);
	mergeSort(mid+1,R);
	merge(L,mid,R);
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(long long i=0;i<s.length();i++){
		long long v=s[i]-48;
		if(0<=v&&v<=9) a[++k]=v;
	}
	mergeSort(1,k);
	for(long long i=k;i>=1;i--) cout<<a[i];
	return 0;
}
