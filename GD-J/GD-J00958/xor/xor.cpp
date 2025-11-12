#include<bits/stdc++.h>
using namespace std;
int n,k,a[1001],xr[1001][1001],z1,in[1000001];
long long ans;
struct node{
	int l,r,ct;//ct指冲突的数量 
}z[1000001];
bool cmp(node x,node y){
	if(x.ct!=y.ct)return x.ct<y.ct;
	if(x.l!=y.l)return x.l<y.l;
	else{
		return x.r<y.r;
	}
}
bool ch(int x,int y){//判断重合 
	return (z[x].r>=z[y].l)&&z[x].l<=z[y].r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)xr[i][j]=a[i];
			else if(j>i){
				xr[i][j]=xr[i][j-1]^a[j];
			}else{
				xr[i][j]=-10086;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(xr[i][j]==k){
				z1++;
				z[z1].l=i;
				z[z1].r=j;
				for(int m=1;m<z1;m++){
					if(ch(z1,m))z[z1].ct++;
				}
			}
			//cout<<xr[i][j]<<' ';
		}
		//cout<<endl;
	}
	sort(z+1,z+z1,cmp);
	//for(int i=1;i<=z1;i++){
	//	cout<<z[i].ct<<' '<<z[i].l<<' '<<z[i].r<<endl;
	//}
	for(int i=1;i<=z1;i++){
		int d=0;
		for(int j=1;j<=ans;j++){
			//cout<<i<<' '<<j<<' '<<z[i].r<<'-'<<z[j].l<<' '<<z[i].l<<'-'<<z[j].r<<endl;	
			if(ch(i,in[j])){
							
				d=1;
				break;
			}
		}
		if(d==0){
			ans++;
			in[ans]=i;
		}
	}
	
	//for(int i=1;i<=ans;i++)cout<<in[i]<<endl;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
