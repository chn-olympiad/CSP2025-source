#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<'a'){
			a[j]=s[i];
			j++;
		}
	}
	for(int i=0;i<j-1;i++){
		for(int k=i+1;k<=j-1;k++){
			if(a[i]<a[k]){
			int x=a[i];
			a[i]=a[k];
			a[k]=x;
			}
		} 
		
	} 
	for(int i=0;i<=j-1;i++){
		cout<<a[i];
	}
	return 0;
}
