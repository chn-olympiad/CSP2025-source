#include<bits/stdc++.h>
using namespace std;
string s,n;
int a[1500],b[1500],m=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s='0'+s;
	int i=1,j=1;
	while(s[j]){
		if(s[j]>='0'&&s[i]<='9'){
		a[i]=s[j];
		i++;
		j++;	
			}
			else{
				j++;
			}
	}
	sort(a+1,a+1+i);
	for(;i>=1;i--){
		cout<<char(a[i]);
	}
	return 0;
} 
