#include<bits/stdc++.h>
using namespace std;
long long a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long n=s.size();
	for(long long i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int cnt=s[i]-'0';
			a[cnt]++;
		}
	}
	bool fl=0;
	for(long long i=9;i>=0;i--){
		if(a[i]!=0){
			if(i!=0){
				fl=1;
				for(long long j=0;j<a[i];j++){
					cout<<i;
				}
			}else{
				if(fl==0){
					cout<<0;
				}else{
					for(long long j=0;j<a[i];j++){
						cout<<i;
					}	
				}
			}
		}
	}
	return 0;
} 
