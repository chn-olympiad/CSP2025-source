#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[105];
int XiaoR;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	    scanf("%d",&a[i]);
	XiaoR=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1,j=n*m;i<=j;i++,j--)
	    swap(a[i],a[j]);
	for(int i=1,num=1;i<=m;i++){
		if(i%2==1)
			for(int j=1;j<=n;j++,num++)
			    if(a[num]==XiaoR){
			        cout<<i<<" "<<j;
			        fclose(stdin);
	                fclose(stdout);
	                return 0;
			    }
		if(i%2==0)
			for(int j=n;j>=1;j--,num++)
			    if(a[num]==XiaoR){
			        cout<<i<<" "<<j;
			        fclose(stdin);
	                fclose(stdout);
	                return 0;
			    }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}