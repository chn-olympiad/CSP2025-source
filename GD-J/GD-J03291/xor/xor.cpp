#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500007];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num+=a[i];
	}
	if(k==1){
		cout<<num;
		return 0;
	}
	num=n-num;
	for(int i=1;i<=n;i++){
		if(a[i]+a[i+1]==2){
			num++;
			i++;
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	//system("fc xor.out ans.out");
	return 0;
}
