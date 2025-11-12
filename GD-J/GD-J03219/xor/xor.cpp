#include<bits.stdc++.h>
using namespace std;
int n, a, cut,k,ans;
int main(){
	cin>>n>>k;
	for(int i = 0;i<n;i++){
		cin>>a;
		ans^=a;
		
		if(ans==k){
			cut++;
			ans = 0;
		}
	}
	cout<<cut;
}
