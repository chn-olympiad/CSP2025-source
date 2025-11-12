#include<bits/stdc++.h>
using namespace std;
int s[5005];
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int a;
	cin>>a;
	for(int d=1;d<=a;d++){
		cin>>s[d];
	}
	sort(s+1,s+a+1);
	if(s[1]+s[2]>s[3]){
		cout<<1;
	}
	else{
		cout<<0;
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
