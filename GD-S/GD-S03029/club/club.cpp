#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int maxx = 0;
		int sum = 0;
		int s = n;
		s/=2;
		int x = 0,y = 0,z = 0;
		for(int i = 1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a>b&&a>c&&x<=s){
				maxx = a;
				x++;
			}
			else if(b>a&&b>c&&y<=s){
				maxx = b;
				y++;
			}
			else if(c>a&&c>b&&z<=s){
				maxx = c;
				z++;
			}
			sum+=maxx;
		}
		cout<<sum<<'\n';
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 
