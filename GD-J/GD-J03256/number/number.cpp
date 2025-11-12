#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+10;
int b[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	int k=0;
	cin>>a;
	for (int i=0;i<a.size();i++){
		if (a[i]-48<=9){
			b[k]=int (a[i]-48);
			k++;
		}
	}
	sort(b+0,b+k); 
	int s=0;
	for (int i=k-1;i>=0;i--){
		s+=b[i];
		if (i==0){
			break;
		}
		s=s*10;
	}
	cout<<s;
	
	return 0;
}
