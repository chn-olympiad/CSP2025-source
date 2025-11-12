#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int main(){
	freopen("number.in","i",stdin );
	freopen("number.out","o",stdout );
	string a;
	long long b[15]={};
	cin>>a;
	long long c=a.length();
	for(int i=9;i>=0;i--){
		b[i]=0;
	}
	for(int i=0;i<c;i++){
		int t=0;
		if(a[i]>='0' && a[i]<='9'){
			t=a[i]-'0';
			b[t]++;
		}
		
    }
    for(int i=9;i>=0;i--){
		for(int j=0;j<b[i];j++){
			cout<<i;
		}
	}
	
	return 0;
}
