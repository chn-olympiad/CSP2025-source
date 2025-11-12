#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	long long n=0,m=0;
	string s,a,b,c;
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		int k=s[i];
		if(k=='1'||k=='2'||k=='3'||k=='4'||k=='5'||k=='6'||k=='7'||k=='8'||k=='9'||k=='0'){
			a+=s[i];
			m++; 
		}
	}
	for(int j=0;j<=m;j++){
		for(int i=0;i<=m;i++){
			if(a[i+1]>=a[i]){
				c[0]=a[i];
				a[i]=a[i+1];
				a[i+1]=c[0];
			}	
		}
	}
	cout<<a;
	return 0;
}
