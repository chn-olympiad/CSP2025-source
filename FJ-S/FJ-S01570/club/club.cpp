#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,sum=0,total=0;
	int x,y,z;
	int n[6],s[6],a[100005][4];
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n[i];
		for(int j=1;j<=n[i];j++){
			for(int k=1;k<=3;k++){
				cin >> a[j][k];
			}
				
		}
	}
	for(int i=1;i<=t;i++){
		int total = 0;
		for(int j=1;j<=n[i];j++){
			int sum = 0;			
			x=a[j][1];
			y=a[j][2];
			z=a[j][3];
			if(x>=y)  sum=x;
			else sum=y;
			if(z>=sum)  sum=z;
			
			total += sum;
			
		}
		cout << total << endl;
	}
	
	return 0;
}
