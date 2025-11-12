#include<bits/stdc++.h>
using namespace std;
int yh(int l,int r,int a[]){
	int s=a[l];
	for(int i=l+1;i<=r;i++){
		s=s^a[i];
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+5]={0},s[n+5]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int w=1;w<=n;w++){
		for(int i=1;i<=n;i++){
			for(int j=1;j+i<=n;j++){
				if(yh(j,i+j-1,a)==k){
					i=i+j;
					s[w]++;
					j=0;
					
				}
				
			}

		}
		s[w]=max(s[w],s[w-1]);
	}
	cout<<s[n];
	return 0;
}
