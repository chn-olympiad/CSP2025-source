 #include<bits/stdc++.h>
 using namespace std;
 int n,m;
 int a[105];
 int b[15][15];
 int main(){
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
 	scanf("%d%d",&n,&m);
 	for(int i=1;i<=n*m;i++){   
	    scanf("%d",&a[i]);	
	}
	int R=a[1];
	int p=n*m;
	sort(a+1,a+p+1);
	for(int i=1;i<=p;i++){
		int temp=i/n;
		if(i<=n){
			b[i][1]=a[p-i+1];
			continue;
		}
		if(i%n==0&&temp%2==0){
			b[1][temp]=a[p-i+1];
			continue;
		}
		if(i%n==0&&temp%2==1){
			b[n][temp]=a[p-i+1];
			continue;
		}
		if(temp%2==1){	
		    b[n-i%n+1][temp+1]=a[p-i+1];
			continue;
		}else if(temp%2==0){
			b[i%n][temp+1]=a[p-i+1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==R){
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
 	return 0;
 }
