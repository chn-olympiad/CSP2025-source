#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,ans,i,j,c;
int a[1000009];
int t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	c=s.size();
	j=1;
	for(i=0;i<c;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-48;
			t[a[j]]++;
			j++;
		}
	}
	
	for(i=9;i>=0;i--){
		if(t[i]>=1){
		
			for(j=1;j<=t[i];j++){
				cout<<i;
			}	
		}
	}
	return 0;
}
/*
in:
90io0

out:
900
*/
