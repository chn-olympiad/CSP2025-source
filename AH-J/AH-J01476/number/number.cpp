#include<bits/stdc++.h>
using namespace std;
string b;
int a[1000000];
int s=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	int n=b.size();
	for(int i=0;i<n;i++){
		if(b[i]>=48&&b[i]<=57){
			a[s++]=b[i]-'0';
		}	
	}
	for(int i=0;i<s;i++){
		int maxn=i;
		for(int j=i+1;j<s;j++){
			if(a[j]>=a[maxn]){
				maxn=j;	
				
			}
		}
			cout<<a[maxn];
			swap(a[i],a[maxn]);
	}
	return 0;
	}
