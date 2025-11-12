#include<bits/stdc++.h> 
using namespace std;
int main(){
	
	string s;
	cin>>s;
	int n;
	char a[10] = {1,2,3,4,5,6,7,8,9,0};
	n = s.size();
	char b[20] = {};
	for(int i = 0;i<=n;i++){
		b[i] = s[i];
		 
		for(int j = 0;j<=n;j++){
			if(s[i] == a[j]){
				b[i] = s[j];
			
			cout<<b[i];
			}
		}
	}
	


}
