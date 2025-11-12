#include<bits/stdc++.h>
using namespace std;
int b[110];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,ans,x=1,y=1,k=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	ans=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==ans){
			cout<<y<<" "<<x<<endl;
			break;
		}
		if(x==n){
			if(k==0){
				k=1;
				x++;
			}else{
				k=0;
				x--;
			}
			y++;
		}
		if(k==0){
			x++;
		}else{
			x--;
		}
	}
	fclose(stdin);
	fclose(stdout);
      
    return 0;
}

