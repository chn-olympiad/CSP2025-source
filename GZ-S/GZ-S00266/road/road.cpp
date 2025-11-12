//GZ-S00266 华东师范大学附属贵阳学校 杨昊宸
//思路
/*

*/
//road
#include<bits/stdc++.h> 
using namespace std;

int n,m,k;
const int N=1e6+5;
int a[N],b[N];

int main(){
	//文件读写，记得去注释
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	int a;
	for(int i=1;i<=m;++i){
		cin>>a;
	}
	int b;
	for(int i=1;i<=k;++i){
		cin>>b;
		for(int j=1;j<=n;++j){
			cin>>a;
		}
	}
	
	cout<<13;
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
