#include<bits/stdc++.h>
using namespace std;
long long number[10];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]-'0'<=9){
			number[a[i]-'0']++;
		}
	}
    for(int i=9;i>=0;i--){
    	while(number[i]>0){
    		cout<<i;
    		number[i]--;
		}
	} 
	return 0;
} 