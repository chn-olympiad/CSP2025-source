#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	char s[1000];
	int m,n,p[100],a,j,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
		p[0]=s[1];
		sort(s+n*m,s+n*m+1);
		if(s[i]==p[0]) a=i;
		for(int j=1;j<=n;j++){
			if(s[i]%n==j){
				for(int x=1;x<=m;x++){
					if(s[i]%2==1 && s[i]%m==x) x=x;
					else if(s[i]%2==0 && s[i]%m+s[i]-m==x) x=x;
				}
		    }
		}
	}
	cout<<j<<x<<endl;
	return 0;
} 
