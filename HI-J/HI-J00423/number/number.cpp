#include<bits/stdc++.h>
using namespace std;
string x;
long long a[1000005];
bool soc(long long i,long long l){
	return i>l;
}
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;long long o=0;
	for(long long i=0;i<x.size();i++){
		if(x[i]=='0'){
			a[o]=0;o++;
		}if(x[i]=='1'){
			a[o]=1;o++;
		}if(x[i]=='2'){
			a[o]=2;o++;
		}if(x[i]=='3'){
			a[o]=3;o++;
		}if(x[i]=='4'){
			a[o]=4;o++;
		}if(x[i]=='5'){
			a[o]=5;o++;
		}if(x[i]=='6'){
			a[o]=6;o++;
		}if(x[i]=='7'){
			a[o]=7;o++;
		}if(x[i]=='8'){
			a[o]=8;o++;
		}if(x[i]=='9'){
			a[o]=9;o++;
		}
	}sort(a,a+o,soc);
	for(long long i=0;i<o;i++){
		cout<<a[i];
	}
	
	return 0;
} 
