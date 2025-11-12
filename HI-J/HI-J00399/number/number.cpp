#include<bits/stdc++.h>
using namespace std;

char s[1000010];
int n,a,x=0;

int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++){
	if(n>(n-1)){
		n=n-1;
	}
	}
    cout<<n;
	return 0;
}

