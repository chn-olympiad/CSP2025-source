#include<bits/stdc++.h>
using namespace std;
int a[5005];
int jc(int num){
	int ans=1;
	while(num!=0){
		ans*=num;
		num--;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	
	fclose(stdin);
	fclose(stdoout);
	
	return 0;
}
