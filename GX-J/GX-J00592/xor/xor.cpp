#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k,s,max=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
	cin>>s;
	    if(s>=max){
		max=s;
		}
	}
	cout<<max;
}
