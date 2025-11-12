#include<bits/stdc++.h>
using namespace std;
int n,m;
int a1;
int b[105];
int c,r;
bool cmp(int a,int b){
	if(a<b){
		return 0;
	}
	return 1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	a1=b[1];
	sort(b+1,b+n*m+1,cmp);
	int i=0;
	bool cx=false;
	for(c=1;c<=m;c++){
		if(c%2==0){
			for(r=n;r>=1;r--){
				i++;
				if(b[i]==a1){
					cx=true;
					break;
				}
			}
		}else{
			for(r=1;r<=n;r++){
				i++;
				if(b[i]==a1){
					cx=true;
					break;
				}
			}
		}
		if(cx){
			break;
		}
	}
	cout<<c<<" "<<r;
	
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
