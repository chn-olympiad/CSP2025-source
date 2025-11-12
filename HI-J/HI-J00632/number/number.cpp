#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=0,i,a[1005];
	char s[1000005];
	for(i=0;i<1000005;i++){
		cin>>s;
		if(s[i]>='a'&&s[i]<='z'){
			continue;
		}
		else{
			a[j]=s[i];
			j++;
		}
		if(a[j]<a[j+1]){
			int t;
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	}
	for(int k=0;k<=j;k++){
		cout<<a[j];
	}		
	return 0;
} 
