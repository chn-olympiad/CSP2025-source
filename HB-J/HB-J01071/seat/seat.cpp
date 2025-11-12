#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y,r,nm;
bool f=true;
int s[1200];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if((n>=3&&m>1)||(m>=3&&n>1)){
		cin>>s[1];
		if(s[1]!=n*m)f=false;
		if(f)cout<<"1 1";
		else if(m%2==0)cout<<m<<" 1";
		else cout<<m<<" "<<n;
	}
	else{
		nm=n*m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[m*(i-1)+j];
		}
	}
	int xs=s[1];
	for(int i=1;i<=nm;i++){
		for(int j=i;j<=nm;j++){
			if(s[j]>s[i]){
				int t=s[j];
				s[j]=s[i];
				s[i]=t;
			}
		}
	}
	for(int i=1;i<=n*m;){
		if(i%2==1){
			if(y+1<=n){
				y++;
				r=n*(x-1)+y;
			}
			else {
				i++;
				x++;
				r=n*(x-1)+1;
			}
			
		}
		else if(i%2==1){
			if(y-1>0){
				y--;
				r=n*x-y+1;
			}
			else {
				i++;
				x++;
				r=n*(x-1)+1;
			}
		}
		if(s[r]==xs){
			cout<<x<<" "<<y;
			return 0;
		}
	}
	}
	return 0;
}
