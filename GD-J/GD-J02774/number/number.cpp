#include<bits/stdc++.h>
using namespace std;
char a[1000006];
long long s,ans,b[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long i=0;i<strlen(a);i++){
		if(a[i]=='1'){
			s++;
			b[1]++;
		}else if(a[i]=='2'){
			s++;
			b[2]++;
		}else if(a[i]=='3'){
			s++;
			b[3]++;
		}else if(a[i]=='4'){
			s++;
			b[4]++;
		}else if(a[i]=='5'){
			s++;
			b[5]++;
		}else if(a[i]=='6'){
			s++;
			b[6]++;
		}else if(a[i]=='7'){
			s++;
			b[7]++;
		}else if(a[i]=='8'){
			s++;
			b[8]++;
		}else if(a[i]=='9'){
			s++;
			b[9]++;
		}else if(a[i]=='0'){
			s++;
			b[0]++;
		}
	}
	int l=9; 
	for(long long i=9;i>=0;i--){
		if(b[i]==0) continue;
		for(int j=1;j<=b[i];j++){
			cout<<i;
		}
	}
	return 0;
}
