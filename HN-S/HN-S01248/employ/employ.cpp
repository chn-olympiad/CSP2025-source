#include<bits/stdc++.h>
using namespace std;
int brr[100001];
int fjc(int f){
	int i=0;
	while(brr[i]!=0){
		brr[i]*=f;
		while(brr[i]>=10){
			brr[i]-=10;
			brr[i+1]+=1;
		}
		i++;
	}
	return i;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	brr[0]=1;
	cin>>n>>m;
	long long a=0,b=0;
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]=='0'){
			a++;
		}
		else{
			b++;
		}
	}
	long long arr[n+1];
	bool bl=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>1){
			bl=1;
		}
	}
	if(b>m){
		cout<<0;
		return 0;
	}
	return 0;
} 
