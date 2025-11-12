#include<bits/stdc++.h>
using namespace std;
int n,m,x,b[105],y,xx=1,yy=1;
int main(){//rp=INT_MAX;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&b[i]);
	}
	x=b[1];
	sort(b+1,b+n*m+1,greater<int>());
	while(++y<=n*m){
		if(b[y]==x){
			cout<<xx<<' '<<yy;
			break;
		}
		if(yy!=n&&xx%2==1)yy++;
		else if(yy==n&&xx%2==1)xx++;
		else if(yy!=1&&xx%2==0)yy--;
		else if(yy==1&&xx%2==0)xx++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
