#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,re;
string a;
int c[1000],b[1000];
long long answer,sum;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++) b[i]=i;
	for(int i=1;i<=n;i++) cin>>c[i];
	re=0;
	sum=0;
	for(int i=1;i<=n;i++){
		if(a[i-1]=='0') re++;
		else{
			if(re>=c[b[i]]) re++;
			else{
				sum++;
			}
		}		
	}
	if(sum>=m) answer++;
	while(next_permutation(b+1,b+n+1)){
		re=0;
		sum=0;
		for(int i=1;i<=n;i++){
			if(a[i-1]=='0') re++;
			else{
				if(re>=c[b[i]]) re++;
				else{
					sum++;
				}
			}		
		}
		if(sum>=m) answer++;
	}
	cout<<answer%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
