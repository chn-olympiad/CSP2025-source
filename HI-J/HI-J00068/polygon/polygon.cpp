#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
	string m[5005];
    cin >> n;
    for (int i=3;i<=n;i++)
    {
    	s=m[i]+m[i];
		if(s*2==n){
			cout << n%2;
		}
	} 
	cout <<"9";
	return 0;
}

