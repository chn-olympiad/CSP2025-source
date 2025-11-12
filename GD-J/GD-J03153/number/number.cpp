#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x;
    int a[15] = {};
    cin >> x;
    for(int i = 0;i <= x.size();i++){
    	if(x[i] <= '9' && x[i] >= '0'){
    		int num = x[i] - 48;
    		a[x[i] - 48]++;
		}
	}
	for(int i = 10;i >= 0;i--){
		if(a[i]){
			for(int j = 1;j <= a[i];j++){
				cout << i;	
			}
		}
	}
    return 0;
}
