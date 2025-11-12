#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int su[n*m],l[n*m],s[n+1][m+1],xm;
	for(int i=0;i<n*m;i++){
		cin>>su[i];
	}
	xm=su[0];
	int ma=0,j,z=0;
	for(int i=0;i<n*m;i++){
		ma=0;
		for(int i=0;i<n*m;i++){
			if(su[i]==-1)continue;
			if(su[i]>ma){
				ma=su[i];
				j=i;
			}
		}
		su[j]=-1;
		l[z]=ma;
		z++;
	}
	int a=1,b=1;
	b=1;
	for(int i=0;i<n*m;i++){
		if(a%2==1){
			if(b<=n){
				if(l[i]==xm){
					cout<<a<<" "<<b;
					break;
				}
				else{
					s[b][a]=l[i];			
					b++;
				}
			}
			else{
				a++;
				b=m;
				if(l[i]==xm){
					cout<<a<<" "<<b;
					break;
				}
				s[b][a]=l[i];
			}
		}
		else{
			if(b>=1){
				if(l[i]==xm){
					cout<<a<<" "<<b;
					break;
				}
				else{
					s[b][a]=l[i];			
					b--;
				}
			}
			else{
				
				a++;
				b=1;
				if(l[i]==xm){
					cout<<a<<" "<<b;
					break;
				}
				s[b][a]=l[i];
			}
		}
	}
	
	//3 3
	//94 95 96 97 98 99 100 93 92

	return 0;
}
