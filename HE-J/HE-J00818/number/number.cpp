#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
string s;
int main(){
	int r=0;
	while(true){
		cin>>a[i];
		i++;
		if(a[i]!>='0' && a[i]!<='9'){
			break;
		}
	}


	for(int i=1;i<=r;i++){
	
		sort(a[i],a[i+1]);
	}
	for(int i=1;i<=r;i++){
		cout<<a[i]; 
	}



		
	
	return 0;
}

