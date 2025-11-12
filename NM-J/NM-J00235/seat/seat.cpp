#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int b[102],w,n,m,fen;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	fen=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==fen){
			w=i;
			break;
		}
	}
	if(w%n==0){
		if((w/n)%2==0){
			cout<<w/n<<" "<<1;
		}
		else{
			cout<<w/n<<" "<<n;
		}
	}
	else{
		if(w/n==0){
			cout<<1<<" "<<w;
		}
		else{
			if((w/n)%2!=0){
				cout<<w/n+1<<" "<<n-(w%n)+1;
			}
			else{
				cout<<w/n+1<<" "<<w%n;
			}
		}
	}
	return 0;	
} 
