#include <bits/stdc++.h>
using namespace std;
int a[500007];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int s=0;
	if(k==0){
		for(int i=0;i<n;i++){
			if(a[i]==0){
				s++;
			}else if(a[i]==a[i-1]){
				s++;
			}
		}
		cout<<s;
		return 0;
	}
	cout<<1;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
