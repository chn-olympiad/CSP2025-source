#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+3;
long long a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=1;
	string s;
	cin>>s;
	long long m=s.size();
	
	for(long long i=0;i<m;i++){
		
		if(s[i]=='1'){
			a[1]++;
			continue;
		}
		if(s[i]=='2'){
			a[2]++;
			continue;
		}
		if(s[i]=='3'){
			a[3]++;
			continue;
		}
		if(s[i]=='4'){
			a[4]++;
			continue;
		}
		if(s[i]=='5'){
			a[5]++;
			continue;
		}
		if(s[i]=='6'){
			a[6]++;
			continue;
		}
		if(s[i]=='7'){
			a[7]++;
			continue;
		}
		if(s[i]=='8'){
			a[8]++;
			continue;
		}
		if(s[i]=='9'){
			a[9]++;
			continue;
		}
		if(s[i]=='0'){
			a[0]++;
			
		}
	}
	for(int i=9;i>=0;i--){
		for(long long j=1;j<=a[i];j++){
			cout<<i;
		} 
	}
	
	
	
	return 0;
}