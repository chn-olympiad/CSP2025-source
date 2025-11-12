#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[10001];
int x,y;
int v;
int b=1;

int qwe(int w,int e){
	return w>e;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	v=a[1];
	sort(a+1,a+(n*m)+1,qwe);
	x=1;
	y=1;
	if(a[1]==v){
		cout<<1<<' '<<1;
	}
	else{
		for(int i=2;i<=n*m;i++){
			if(b==1&&x<n){
				x++;
			}
			else if(b==0&&x>1){
				x--;
			}
			else if(b==1&&x==n){
				y++;
				b=0;
			}
			else if(b==0&&x==1){
				b=1;
				y++;
			}
			if(a[i]==v){
				cout<<y<<" "<<x;
				break;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}