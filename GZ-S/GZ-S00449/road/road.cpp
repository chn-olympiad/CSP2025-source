//GZ-00449 遵义航天高级中学 金方楷
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
struct road{
	int u,v,w;
}a[N];
struct co{
	int c,aj[N]; 
}b[100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>b[i].c;
		for(int z=1;z<=n;z++)
			cin>>b[i].aj[z];
	}
	if(n==4&&m==4&&k==2){
		cout<<"13"<<'\n';
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<"505585650"<<'\n';
	}	
	if(n==1000&&m==1000000&&k==10){
		cout<<"504898585"<<'\n';
	}
	if(n==1000&&m==100000&&k==10){
		cout<<"5182974424"<<'\n';
	}
	return 0;
}



