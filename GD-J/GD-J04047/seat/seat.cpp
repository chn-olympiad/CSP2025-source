#include <bits/stdc++.h>
using namespace std;
int n,m,scores[101],seats[11][11];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>scores[i];
		seats[i][1]=i;
	}
	int m_base=scores[1];
	sort(scores+1,scores+1+n*m,cmp);
	int m_x;
	for(int i=1;i<=n;i++){
		m_x=2*n-(2*(i-1)+1);
		for(int j=2;j<=m;j++){
			seats[i][j]=seats[i][j-1]+m_x;
			m_x=2*n-m_x;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(scores[seats[i][j]]==m_base){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
