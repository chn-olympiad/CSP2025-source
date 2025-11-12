#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b;
	int s[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	b=s[1];
	sort(s+1,s+1+n*m,cmp);
	int k=1,j=1,a=1;
	for(int i=1;j<=m;i+=a){	
		if((i%n==1&&i>n)||(i==0&&j!=1)){
			if(j%2==1){
				i=n;a=-1;
			}
			else{
				i=1;a=1;
			}
			j++;
		}
		if(s[k]==b){
			cout<<j<<" "<<i;
			break;
		}
		k++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
