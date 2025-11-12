#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum=0,num,x,y;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int p=-1,q=-1;
	for(x=1;x<=n;x++){
		for(y=1;y<=x;y++){
			if((a[x]==0 && a[y]==1) || (a[x]==1 && a[y]==0)){
				sum+=1;
			}
			else if((a[x]==1 && a[y]==1) || (a[x]==0 && a[y]==0)){
				sum+=0;
			} 
		}
		if(sum==k && ((x<p && y<p) || (x>q && y>q))){
			num++;
			p=y,q=x;
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
