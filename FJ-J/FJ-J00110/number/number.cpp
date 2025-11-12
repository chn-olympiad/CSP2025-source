#include<bits/stdc++.h>
using namespace std;
int a[11];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    int sum;
    cin>>s;
    for(int i=0;i < s.size();i++){
    	if(s[i] >= '0' && s[i] <= '9'){
    		sum = s[i] - '0';
    		a[sum]++; 
		}
	}
	for(int i = 9;i >= 0;i--){
		int t = a[i];
		while(t--){
			cout<<i;
		}
	}

	return 0;
} 
