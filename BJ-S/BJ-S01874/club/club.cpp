#include <bits/stdc++.h>
using namespace std;
int t,n,a[100086][3],x,y,z,c,k[100086],l[100086],xl,yl,zl;
void lushu(){
	for (int i = 1; i <= n; i++){
		k[i]=a[i][1];
		l[i]=k[i];
	}
	sort (k+1,k+n+1);
	c=0;
	for (int i = n; i >= n/2; i--)
		c += k[i];
	cout << c;
}
void clubb(){
	c=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 3; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++){
		if (a[i][1] >=a[i][2]&&a[i][1]>=a[i][3]){
			c+=a[i][1];
			x++;
			if(a[i][2] >= a[i][3]) yl++;
			else zl++;
		}
		else if (a[i][2] >=a[i][1]&&a[i][2]>=a[i][3]){
			c+=a[i][2];
			y++;
			if(a[i][1] >= a[i][3]) xl++;
			else zl++;
		}
		else if (a[i][3] >=a[i][1]&&a[i][3]>=a[i][2]){
			c+=a[i][3];
			z++;
			if(a[i][1] >= a[i][2]) xl++;
			else yl++;
		}
	}
	if (x <= n/2 && y <= n/2 && z <= n/2){
		cout << c;
	}
	else
	{
		lushu();
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin >> t;
	for (int i = 1; i <= t; i++)
		clubb();
}
