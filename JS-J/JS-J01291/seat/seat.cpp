#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","s",stdout);
	int m,n;
	cin>>n>>m;
	int x=1,y=0;
	int s[101];
	int r;
	int ord;
	cin>>r;
	s[1]=r;
	for(int i=1;i<=n*m-1;i++){
		cin>>s[i+1];
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m-1;i++){
		if(s[i]==r){
			ord=i;
		}
	}
	int add=0;
	int flag=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-add;j++){
			if(ord){
				if(x%2){
					y++;
					ord--;
				}else{
					y--;
					ord--;
				}
			}else{
				cout<<x<<" "<<y;
				flag=0;
				break;
			}
		}
		x++;
		ord--;
		add=1;
		if(!ord && flag){
			cout<<x<<" "<<y;
				break;
				flag=0;
		}
		if(!flag){
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
