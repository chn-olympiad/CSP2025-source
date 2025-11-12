#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("numder.in","r",stdin);
	freopen("numder.out","w",stdout);
 	int n=1e6+10,i,j;
	char a[n];
	char s[n],y;
	cin>>a[n];
	for(int i=1;i<=n;i++){
		if(int(a[i])<=97){
			s[i]=a[i];
		}
		for(int j=1;j<=i;j++){
			if(s[j]<s[j+1]){
				y=s[j];
				s[j]=s[j+1];
				s[j+1]=y;
			}
		}
		for(int y=1;i<=j;i++){
			cout<<s[i];
		} 
	
	}
	
	return 0;
} 
