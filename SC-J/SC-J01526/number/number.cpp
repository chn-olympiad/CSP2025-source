#include<bits/stdc++.h>
using namespace std;
string s;
unsigned long long a[20],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		l+=s.size();
	}
	
	for(unsigned long long i=0;i<l;i++){
		if(s[i]=='0'){
			a[0]++;
		}if(s[i]=='1'){
			a[1]++;
		}if(s[i]=='2'){
			a[2]++;
		}if(s[i]=='3'){
			a[3]++;
		}if(s[i]=='4'){
			a[4]++;
		}if(s[i]=='5'){
			a[5]++;
		}if(s[i]=='6'){
			a[6]++;
		}if(s[i]=='7'){
			a[7]++;
		}if(s[i]=='8'){
			a[8]++;
		}if(s[i]=='9'){
			a[9]++;
		}	
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int t=1;t<=a[i];t++){
				cout<<i;
			}
		}
	}
	return 0;
} 