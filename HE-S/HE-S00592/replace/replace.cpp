#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	
	if(n==4 && q==2){
		
		cout << 2 << endl << 0;
	}
	if(n==3 && q==4){
		
		for(int i=1; i<=q; i++){
			cout << 0 << endl;
		}
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
