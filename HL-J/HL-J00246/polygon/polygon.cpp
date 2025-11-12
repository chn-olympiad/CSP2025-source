#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,shu[5010],ans=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>shu[i];
	}
	while(n){
		for (int a=1;a<=n-2;a++){
			for (int b=a+1;b<=n-1;b++){
				for (int c=b+1;c<=n;c++){
					if (shu[a]+shu[b]+shu[c]>2*((max(max(shu[a],shu[b]),max(shu[b],shu[c]))),max(shu[a],shu[c]))){
						ans+=1;
					}
				}
			}
		}
		n/=2;
	}
	if (ans%2==0)	cout<<((ans+1)*(ans+2))/2;
	else cout<<((ans+1)*(ans+2))/2-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}