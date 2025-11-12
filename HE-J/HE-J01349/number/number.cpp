#include<bits/stdc++.h>
using namespace std;
int arr[256] ;
int main(){
	string ans;
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	string s;cin >> s;
	for(int i = 0;i < s.size();i++){
		if('0'<=s[i] and s[i] <= '9'){
			
			arr[s[i]]++;
			
		}
		
		
	}
	
	char j = '9';
	
	while(j >= '0'){
	if(arr[j] != 0){
		ans += j;
		arr[j]--;
	}	else{
		j--;
	}

	}	cout << ans;		
		
	
	return 0;
}
