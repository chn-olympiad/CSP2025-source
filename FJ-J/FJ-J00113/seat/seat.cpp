#include<bits/stdc++.h>
using namespace std;

int n,m,up,id;
int s[105];
bool q=1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int ok=n*m;
	for(int i=1;i<=ok;i++){
		cin>>s[i];
	}
	up=s[1];
	sort(s+1,s+ok+1);
	for(int i=ok;i;i--){
		if(s[i]==up){
			id=ok-i+1;
			break;
		}
	}
//	cout<<id<<endl;
	int x=1,y=1;
	for(int i=1;i<id;i++){
		if(q){
			x++;
			if(x>n){
				x--;
				y++;
				q=0;
			}
		}else{
			x--;
			if(x<1){
				x++;
				y++;
				q=1;
			}
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
