#include <bits/stdc++.h>
using namespace std;
int n,m,a[1001],b[1001],i=1,j=1,se,flag=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==a[1]){
			se=i;
			break;
		}
	}
	while(--se){
		if(flag==0){
			j++;
			if(j>m){
				j--;
				i++;
				flag=1;
			}
		}else{
			j--;
			if(j<1){
				j++;
				i++;
				flag=0;
			}
		}
	}
	cout<<i<<' '<<j;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
