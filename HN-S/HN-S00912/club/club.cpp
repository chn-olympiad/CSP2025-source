#include<bits/stdc++.h>
using namespace std;
int aq[1001];
int aw[1001];
int ae[1001];
int main(){
	freopen(title,in,"club.in",stdin);
	freopen(title,out,"club.out",stdout);
	int t,n,a,aq,aw,ae,ar,at;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>aq>>aw>>ae;
			aq[j]=aq;
			aw[j]=aw;
			ae[j]=ae;
		}
		cout<<aq[i]+aw[i]+ae[i];
	}
	fclose(stdin);
	fclose(stdout);
	reture 0
} 
