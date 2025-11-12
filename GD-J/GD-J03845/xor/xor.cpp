#include<bits/stdc++.h>
using namespace std;
int standardd[21],n,m,z=0;
int w[500005][2],ans=0;
bool a[500005][21],q[21],k[21];
bool anss[500005];
void dfs(int o,int ansss){
	for(int i=w[o][0];i<=w[o][1];i++){
		
	}
}
void turnn(int e){
	for(int i=20;i>=0;i--){
		q[i]=e/standardd[i];
		e=e%standardd[i];
	}
}bool r(bool p,bool o){
	if(p==o){
		return 0;
	}else{
		return 1;
	}
}bool t(bool p,bool o){
	if(p){
		return !o;
	}else{
		return o;
	}
}
int main(){
	freopen("xor1.in","r",stdin);
	freopen("xor.ans","w",stdout);//I HATE THIS AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
	//ios::sync_with_stdio(false);
	standardd[0]=1;
	for(int i=1;i<=20;i++){
		standardd[i]=standardd[i-1]*2;
		//cout<<standardd[i]<<"\n";
	}cin>>n>>m;
	turnn(m);
	for(int i=0;i<=20;i++){
		k[i]=q[i];
	}for(int i=0;i<n;i++){
		cin>>m;
		turnn(m);
		for(int j=0;j<=20;j++){
			a[i][j]=q[j];
		}for(int j=0;j<=20;j++){
			if(a[i][j]!=k[j]){
				break;
			}if(j==20){
				w[z][0]=i;
				w[z][1]=i;
				z++;
			}
		}if(i>=1){
			for(int j=0;j<=20;j++){
				q[j]=r(a[i][j],a[i-1][j]);
				a[i][j]=q[j];
			}for(int j=0;j<=20;j++){
				if(a[i][j]!=k[j]){
					break;
				}if(j==20){
					w[z][0]=0;
					w[z][1]=i;
					z++;
				}
			}
		}
	}for(int i=2;i<n;i++){
		for(int j=i;j>=1;j--){
			for(int x=0;x<=20;x++){
				q[x]=t(a[i][x],a[i-j-1][x]);
				if(q[x]!=k[x]){
					break;
				}if(x==20){
					w[z][0]=i-j;
					w[z][1]=i;
					z++;
				}
			}
		}
	}/*for(int i=0;i<z;i++){
		cout<<w[i][0]<<" "<<w[i][1]<<"\n";
	}*/
	}for(int i=0;i<z;i++){
		dfs(i,1);
	}//haven't done AHHHHHHHHHHHHHHHHH
	return 0;
} 
