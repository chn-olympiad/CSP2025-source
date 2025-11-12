#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int t=0;
	int h=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		h=h^x;
		if(h==k){
			t++;
			h=0;
		}
	}
	cout<<t;
}
