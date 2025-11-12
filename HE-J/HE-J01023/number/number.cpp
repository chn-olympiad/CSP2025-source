#include<bits/stdc++.h>
using namespace std;
const int m = 1e6+10;
string a;
char n[m];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int l = 1;
	memset(n,'0',sizeof(n)) ;
	for(int i=0;i<a.size();i++){
		if(a[i] <= '9' && a[i] >= '0') {
			n[l] = a[i];
			l+=1;
		}
	}
	sort(n+1,n+l+1);
	
	int z=-1;
	for(int i = l;i>=1;i--){
		if(n[i] == '0') z++;
		else cout<<n[i];
	} 
	while (z--) cout<<0;
	return 0;
} 
