#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[1000010];
int c[1000010];
int times(int num){
	int ans=1;
	for(int i=1;i<=num;i++){
		ans=ans*i;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int sum=0;
	for(int i=m;i<=n;i++){
		sum+=times(n)/(times(i)*times((n-i)));
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
