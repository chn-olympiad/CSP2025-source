#include<bits/stdc++.h>
using namespace std;
string t;
int a[200],seat[1000][1000];
int n,m,c,r,s,k,g,l;
int main(){
	freopen("seat1.in","r",stdin);
	getline(cin,t);
	l=t.length();
	if(t[1]!=' '){
		g=2;
		n=int(t[1]-'0')+int(t[0]-'0')*10;
		if(t[4]-'0'>=0&&t[4]-'0'<=9){
			m=int(t[3]-'0')*10+int(t[4]-'0');
			g=4;
		}
		else{
			m=int(t[3]-'0');	
			g=3;
		}
	}else{
		g=1;
		n=int(t[0]-'0');
		if(t[3]-'0'>=0&&t[3]-'0'<=9){
			m=int(t[2]-'0')*10+int(t[3]-'0');
			g=3;
		}
		else{
			m=int(t[2]-'0');
			g=2;
		}
	}g+=2;
	int y=0,u=0;
	for(int i=l-1;i>=g-1;i++){
		if(t[i]!=' '){
			a[u]+=int(t[i]-'0')*pow(10,y);
			y++;
		}else{
			u++;
		}
	}
	for(int i=0;i<n*m;i++)cin>>a[i];
	s=a[0];
	sort(a,a+n*m);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				seat[i][j]=a[k];
				k++;
			} 
		}else{
			for(int j=m;j>=1;j--){
				seat[i][j]=a[k];
				k++;
			}
		}
	}for(int i=1;i<=n;i++){
		for(int j=1;i<=m;j++){
			if(seat[i][j]==s){
				c=j;
				r=i;
			}
		}
	}freopen("seat.out","w",stdout);
	cout<<c<<" "<<r;
	return 0;
} 
