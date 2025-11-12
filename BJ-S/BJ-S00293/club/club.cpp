#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t;
int n,a[100010][5];
struct node{
	int n,x;
};
node bst[100010],nbst[100010],wst[100010];
struct peo{
	int a,x,b,y,c,z;
}p[100010];
int mx=-1;
bool cmp1(peo a,peo b){
	return (a.a-a.b)>(b.a-b.b);
}
void slove1(int i,int sum,int x,int y,int z){
	if(x>n/2||y>n/2||z>n/2){
		return ;
	}
	if(i==n+1){
		mx=max(sum,mx);
	}
	else{
		slove1(i+1,sum+a[i][1],x+1,y,z);
		slove1(i+1,sum+a[i][2],x,y+1,z);
		slove1(i+1,sum+a[i][3],x,y,z+1);
	}
}
void algor(){
	for(int i=1;i<=n;i++){
		int x=a[i][1],y=a[i][2],z=a[i][3];
		if(x>=y&&x>=z){
			bst[i]={x,1};
			if(y>=z){
				nbst[i]={y,2};
				wst[i]={z,3};
			}
			else{
				nbst[i]={z,3};
				wst[i]={y,2};
			}
		}
		else if(y>=x&&y>=z){
			bst[i]={y,2};
			if(x>=z){
				nbst[i]={x,1};
				wst[i]={z,3};
			}
			else{
				nbst[i]={z,3};
				wst[i]={x,1};
			}
		}
		else if(z>=x&&z>=y){
			bst[i]={z,3};
			if(y>=x){
				nbst[i]={y,2};
				wst[i]={x,1};
			}
			else{
				nbst[i]={x,1};
				wst[i]={y,2};
			}
		}
	}
	long long sum=0,c[5]={0,0,0,0,0};
	for(int i=1;i<=n;i++){
		p[i]={bst[i].n,bst[i].x,nbst[i].n,nbst[i].x,wst[i].n,wst[i].x};
	}
	sort(p+1,p+1+n,cmp1);
	for(int i=1;i<=n;i++){
		if(c[p[i].x]<n/2){
			c[p[i].x]++;
			sum+=p[i].a;
		}
		else if(c[p[i].y]<n/2){
			c[p[i].y]++;
			sum+=p[i].b;
		}
		else{
			c[p[i].z]++;
			sum+=p[i].c;
		}
	}
	cout<<sum<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		mx=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		if(n<=10){
			slove1(1,0,0,0,0);
			cout<<mx<<endl;
		}
		else{
			algor();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
