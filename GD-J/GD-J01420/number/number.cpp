#include<bits/stdc++.h>
using namespace std;
int b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if('0'==a[i]){
			b[0]++;
		}
		if('1'==a[i]){
			b[1]++;
		}
		if('2'==a[i]){
			b[2]++;
		}
		if('3'==a[i]){
			b[3]++;
		}
		if('4'==a[i]){
			b[4]++;
		}
		if('5'==a[i]){
			b[5]++;
		}
		if('6'==a[i]){
			b[6]++;
		}
		if('7'==a[i]){
			b[7]++;
		}
		if('8'==a[i]){
			b[8]++;
		}
		if('9'==a[i]){
			b[9]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++){
		    cout<<i;
	    }
	}
	return 0;
}
