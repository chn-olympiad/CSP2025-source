#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int s[5005]={},n;
	cin >> n;
	if(n<3){
		return 0;
	}
	else{
		int cha=4,sum=1;
		for(int i=1;i<=n;i++){
			cin >> s[i];
		}
		for(int i=1;i<=n-3;i++){
			sum+=cha;
			cha+=2;
		}
		cout << sum;
	}
	return 0;
}
