#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10010];
long long num=0,n=0;
int main(){
	cin>>s;
	long long len=s.size();
	for(long long i=0;i<len;i+=0){
		for(long long j=0;j<len;j++){
			if(s[j]=='0'){
				a[i]=0;
				i++;
				n++;
			}
			else if(s[j]=='1'){
				a[i]=1;
				i++;
				n++;
			}
			else if(s[j]=='2'){
				a[i]=2;
				i++;
				n++;
			}
			else if(s[j]=='3'){
				a[i]=3;
				i++;
				n++;
			}
			else if(s[j]=='4'){
				a[i]=4;
				i++;
				n++;
			}
			else if(s[j]=='5'){
				a[i]=5;
				i++;
				n++;
			}
			else if(s[j]=='6'){
				a[i]=6;
				i++;
				n++;
			}
			else if(s[j]=='7'){
				a[i]=7;
				i++;
				n++;
			}
			else if(s[j]=='8'){
				a[i]=8;
				i++;
				n++;
			}
			else if(s[j]=='9'){
				a[i]=9;
				i++;
				n++;
			}
		}
		break;
	}
	int maxn=0;
	for(long long i=0;i<n;i++){
		for(long long j=0;j<n;j++){
			if(maxn<a[j]){
				maxn=a[j];
			}
		}
		for(long long j=0;j<n;j++){
			if(maxn==a[j]){
				a[j]=-1;
				break;
			}
		}
		if(maxn==0) num+=0;
		else if(n-i==0) num+=maxn;
		else{
			for(long long j=1;j<=n-i;j++){
				maxn*=10;
			}
			num+=maxn;
		}
		maxn=0;
	}
	cout<<num;
	
	return 0;
}
