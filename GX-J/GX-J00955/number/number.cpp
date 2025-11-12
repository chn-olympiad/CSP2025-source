#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1;
	long long int i,j=0,k;
	cin>>s;
	long long int a=s.size();
	string b[a]={};
	for(i=0;i<a;i++){		
		if(s[i]<'a'){
			b[j]=s[i];
			j++;
		}
	}
	for(i=0;i<j;i++){
		for(k=i+1;k<j;k++){
				if(b[i]<b[k]){
					s1=b[i];
					b[i]=b[k];
					b[k]=s1;
			}
		}
	}
	for(i=0;i<j;i++)cout<<b[i];
	return 0;
}
