#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int a,s,d,f,g,t=0;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>s;
		for(int j=1;j<=s;j++){
			cin>>d>>f>>g;
			if(d>=f&&d>=g)t+=d;
			else if(f>=d&&f>=g)t+=f;
			else t+=g;
		}
		cout<<t<<' ';
		t=0;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
