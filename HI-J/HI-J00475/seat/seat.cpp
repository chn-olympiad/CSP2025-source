#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int q[15][15];
bool comp(int x,int y){return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	if(n<=1){
		if(m<=1){
			cout<<1<<' '<<1;
			return 0;			
		}
		else{
			int k=a[1];
			sort(a+1,a+1+n*m,comp);
			for(int i=1;i<=m;i++){
				if(k==a[i]){
					cout<<i<<' '<<1;
					return 0;
				}
			}
		}
	}
	else if(n<=10&&m<=1){
		int k=a[1];
		sort(a+1,a+1+n*m,comp);
		for(int i=1;i<=n;i++){
			if(k==a[i]){
				cout<<1<<' '<<i;
				return 0;
			}
		}		
	}
	else{
		int minn=0x7f7f7f7f;
		for(int i=1;i<=n*m;i++) minn=min(minn,a[i]);
		for(int i=1;i<=n*m;i++) a[i]-=minn;	
		int k=a[1];
		sort(a+1,a+1+n*m,comp);
		for(int i=1;i<=n*m;i++) if(a[i]==k){k=a[i]; break;}
		cout<<k<<endl;
		int num=0;
		for(int i=1;i<=m;i++){
			if(i%2==0){
				for(int j=n;j>=0;j--){
					num++;
					q[j][i]=num;
				}
			}
			else{
				for(int j=1;j<=n;j++){
					num++;		
					q[j][i]=num;		
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++) cout<<q[i][j]<<' ';
			cout<<endl;
		}
		cout<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(q[i][j]==a[k]){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}	
	}
    return 0;
}

