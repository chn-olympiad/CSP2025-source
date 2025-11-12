#include<bits/stdc++.h>
using namespace std;
struct S{
	int c;
	bool b;
}s[105];
bool cmp(S q,S w){
	return q.c>w.c; 
}
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int d=1;d<=n*m;d++){
		cin>>s[d].c;
		if(d==1){
			s[d].b=1;
		}
		else{
			s[d].b=0;
		}
	}
	sort(s+1,s+n*m+1,cmp);
	int x=1,y=1;
	for(int d=1;d<=n*m;d++){
		if(s[d].b){
			if(y>n){
				y=n;
				x++;
			}
			if(y<1){
				y=1;
				x++;
			}
			cout<<x<<" "<<y;
			break;
		}
		if(y>=1&&y<=n){
			if(x%2==1){
				y++;
			}
			else{
				y--;
			}	
		}
		if(y>n){
			y=n;
			x++;
		}
		if(y<1){
			y=1;
			x++;
		}
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
