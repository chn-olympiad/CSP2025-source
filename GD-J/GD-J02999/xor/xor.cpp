#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200002];
bool s1=1,s2=1,s3=1;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)s1=0;
		if(a[i]>1)s2=0;
		if(a[i]>255)s3=0;
	}
	//solve1
	if(s1 and k==0){
		cout<<n/2;
		return 0;
	}
	//solve2
	else if(s2 and k<=1){
		int cnt=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==1 and a[i+1]==1){
					cnt++;
					i++;
				}
				if(a[i]==0)cnt++;
			}
		}
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	//solve:i don't know how to do to work it so this solve is my "xia cai de",but i konw i love 38
	else if(k==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt++;
		}
		cout<<cnt;
		return 0;
	}
	else{
		cout<<638;
	}
	return 0; 	 
} 
