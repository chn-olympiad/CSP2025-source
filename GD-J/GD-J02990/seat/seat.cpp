#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=0,a[10000]={};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int t=n*m,i=1,j=1,ans=1;
	if(n*m==1||a[1]==x){
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	t-=1;
	while(t--){
		if((i==n&&j%2==1)||(i==1&&j%2==0)){
			j++;
		}else if(j%2==0){
			i--;
		}else{
			i++;
		}
		ans++;
		if(a[ans]==x){
			cout<<j<<" "<<i;
			return 0;
		}
		
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
