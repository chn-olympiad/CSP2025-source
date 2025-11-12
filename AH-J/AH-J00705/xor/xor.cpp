#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=0,s1,s2=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		s=s^a[i];
		if(s==k){
			for(int j=i;j<=n;j++){
				s1=0;
				for(int k=j;k<=n;k++){
					s1=s1^a[k];
					if(s1==k){s2++;}}}}}
	cout<<s2;}
