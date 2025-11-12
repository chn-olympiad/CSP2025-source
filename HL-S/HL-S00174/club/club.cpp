#include <bits/stdc++.h>
using namespace std;
int t,n,a[100010][5],maxx=-1,x,y,z;
void ff(int b,int sum){
	if(b==n){
		maxx=max(maxx,sum);
		//cout<<"m:"<<maxx<<endl;
		return;
	}
	int ave=n/2;
	if(x<ave){
		x++;
		//cout<<"1:"<<sum<<endl;
		ff(b+1,sum+a[b][0]);
		x--;
	}
	if(y<ave){
		y++;
		//cout<<"2:"<<sum<<endl;
		ff(b+1,sum+a[b][1]);
		y--;
	}
	if(z<ave){
		z++;
		//cout<<"3:"<<sum<<endl;
		ff(b+1,sum+a[b][2]);
		z--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int f=0;f<t;f++){
		maxx=-1;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		ff(0,0);
		cout<<maxx<<endl;
	}
	return 0;
}
/*3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/