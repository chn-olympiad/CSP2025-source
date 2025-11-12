#include<bits/stdc++.h>
using namespace std;
long long s[1000005];
long long ans;
int max1=INT_MIN;
int main(){
	int n;
	cin>>n;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>s[i]; 
		if(s[i]>=0){   
		if(s[i]<s[i-1]){
			swap(s[i],s[i+1]);
			max1=max(s[i],s[i+1]);             
			cout<<max1;	
		}
	}
}
	fclose("stdin");	
	fclose("stdout");
	return 0;
}
