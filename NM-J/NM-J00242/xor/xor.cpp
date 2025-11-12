#include<bits/stdc++.h>
using namespace std;
int a[500002];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long k,e=0,b;
	cin >>n>>k;
	for(int i=0;i<n;i++){
		cin >>a[i]; 
	}
	for(int i=0;i<n;i++){
		b=a[i];
		if(a[i]==k){
			e++;
			i++;
		}
		for(int j=i+1;j<n;j++){
			if(b==k){
				e++;
				i=j;
				break;
			}
			b=b&a[j];
		}
	}
	cout <<e;
	return 0;
}
