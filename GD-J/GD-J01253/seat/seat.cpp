//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
int n,m,s[5005],k,u;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	k=s[1];
	int p=n*m;
	sort(s+1,s+p+1);
	for(int i=p;i>=1;i--){
		if(k==s[i]){
			u=p-i+1;
			break;
		}
	}
	int a=u%n;
	int b=u/n;
	if(a==0){
		cout<<b<<' '<<n;
	}
	else {
		b++;
		if(b%2==1){
			cout<<b<<' '<<a;
		}
		else cout<<b<<' '<<n-a+1;
	}
	return 0;
}
