#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a=0,s,n,max=0,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int i=0;i<n;i++){
		cin>>s;
		if(s>=max){
		    max=s;
		}
		a+=s;
	    }
	    if(a>max*2){
			ans+=1
		}
	}
}
