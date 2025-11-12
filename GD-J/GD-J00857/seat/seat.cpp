#include<bits/stdc++.h>
using namespace std;

int n,m;
const int maxn=105;
int a[maxn][maxn],x[maxn];
int len,k=1,cnt,mark;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++)
		cin>>x[i];
	mark=x[1];
	sort(x+1,x+len+1,cmp);
	for(int j=1;j<=m;j++){
		if(k==1){
			for(int i=1;i<=n;i++){
				a[i][j]=x[++cnt];
				if(x[cnt]==mark){
					cout<<j<<" "<<i;
					break;
				}
			}
			k=0;
		}
			
		else{
			for(int i=n;i>=1;i--){
				a[i][j]=x[++cnt];
				if(x[cnt]==mark){
					cout<<j<<" "<<i;
					break;
				}
			}
			k=1;
		}
	}
	return 0;
}
