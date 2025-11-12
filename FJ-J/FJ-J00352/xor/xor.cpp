#include <bits/stdc++.h>
using namespace std;
int a[500500],s[500500];
//l-1 xor r;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	s[i]=s[i-1] xor a[i];
	}
	int num=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((i-1 xor j)==k) num++;
		}
	}
	cout<<num;
	return 0;
} 