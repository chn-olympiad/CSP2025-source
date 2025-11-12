#include<bits/stdc++.h>
using namespace std;
string s;
long long f[1000005],k=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<=n;i++){
		if(s[i]=='0'){
		f[k]=0; k++;
		} 
		if(s[i]=='1'){
		f[k]=1; k++;	
		} 
		if(s[i]=='2'){
		f[k]=2; k++;	
		} 
		if(s[i]=='3'){
		f[k]=3; k++;	
		} 
		if(s[i]=='4'){
		f[k]=4; k++;	
		} 
		if(s[i]=='5'){
		f[k]=5; k++;	
		} 
		if(s[i]=='6'){
		f[k]=6; k++;	
		} 
		if(s[i]=='7'){
		f[k]=7; k++;	
		} 
		if(s[i]=='8'){
		f[k]=8; k++;	
		} 
		if(s[i]=='9'){
		f[k]=9; k++;	
		} 
		}
		for(int i=1;i<=k;i++){
		f[i]=f[i];
		}
		sort(f+1,f+k+1);
		for(int i=k;i>=2;i--){
			cout<<f[i];
		}
	return 0;
}
