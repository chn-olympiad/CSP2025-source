#include<bits/stdc++.h>
using namespace std;
int a[10086];
int n;
int cnt=0;
int s[10086];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
    	s[i]=s[i-1]+a[i];
	}
	for(int i=n;i>=3;i--){
		for(int j=1;j<=i-3;j++){
			if(a[i]*2<s[i]-s[j]){
				cnt++;
			}
		}
	}
	cout<<cnt*3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
