#inculde<bits/stdc++.h>;
using namespace;
int a[1000005];
int main{
	freopen(number.in stdin.r);
	freopen(number.out stdout.w);
	int ans=0;
	for(int i=1;i<=1000005;i++){
		a[i]=0;
	}
	for(int i=1;i<=1000000;i++){
		int s;
		cin>>s;
		a[i]=s;
		if(a[i]==1||a[i]==2||a[i]==3||a[i]==4||a[i]==5||a[i]==6||a[i]==7||a[i]==8||a[i]==9||a[i]==0){
			for(int j=1;j<=i;j++){
				if(a[i]>=a[i-1]){
					ans=ans*10+a[i];
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
