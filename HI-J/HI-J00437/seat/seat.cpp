#include <bits/stdc++.h>
using namespace std;
int n,m,s[105],b,f;
int main(){
	fropen("seat.in","r",stdin);
	fropen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>s[i];
	b=s[1];
	sort(s+1,s+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(s[i]==b){
			f=i;
		}
	}
	if(f-1<=m){
		cout<<m-(f-m)<<" ";
		if(m-(f-m)<=1)
			cout<<f-1;
		else if(1<m-(f-m)&&m-(f-m)<n)
			cout<<f+1;
		else
			cout<<f-(m-(f-m))+1;
	}
}
