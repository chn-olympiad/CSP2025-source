#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a;
	cin>>a;
	
	for(int i=1;i<=a;i++){
		
		int p;
		cin>>p;
		int s[p][3];
		int sum=0;
		for(int j=1;j<=p;j++){
			cin>>s[j][1]>>s[j][2]>>s[j][3];
			sum+=max(s[j][1],max(s[j][2],s[j][3]));
		}
		cout<<sum<<endl;
	}
	return 0;
}
