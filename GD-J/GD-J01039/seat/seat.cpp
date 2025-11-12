#include<bits/stdc++.h>
using namespace std;
int a[10006];
int b[106][106];
int n,m;
int s;
int t,h;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	int c=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				b[j][i]=a[c];
				if(b[j][i]==s)t=j,h=i;
				c++;
			}
		}
		if(i%2==0){
			for(int j=m;j>0;j--){
				b[j][i]=a[c];
				if(b[j][i]==s)t=j,h=i;
				c++;
			}
		}
	}
	cout<<h<<' '<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
