#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
int n, num=0;
int b=0, c=0, d=0;
int x=0, y=0, z=0;
bool check()
{
	int ans=n/2;
	for(int i=1; i<=n; i++){
		if(x<=ans&&y<=ans&&z<=ans)
			num=b+c+d;
		else{
			if(x>ans){
				b-=a[i][1];
				if(a[i][2]>=a[i][3])
					c+=a[i][2];
				else
					d+=a[i][3];
				x--;
				}
			else if(y>ans){
				c-=a[i][2];
				if(a[i][1]>=a[i][3])
					b+=a[i][1];
				else
					d+=a[i][3];
				y--;
			}
			else if(z>ans){
				d-=a[i][3];
				if(a[i][1]>=a[i][2])
					b+=a[i][1];
				else
					d+=a[i][2];
				z--;
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=3; j++){
				cin>>a[i][j];
			}
		for(int i=1; i<=n; i++)
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				b=b+a[i][1]; x++;
			}
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				c=c+a[i][2]; y++;
			}
			else if(a[i][3]>a[i][1]&&a[i][3]>=a[i][2]){
				d=d+a[i][3]; z++;
			}
		check();
		cout<<num<<endl;
	}
	return 0;
} 
