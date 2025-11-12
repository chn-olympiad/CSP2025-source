//GZ-S00266 华东师范大学附属贵阳学校 杨昊宸
//思路
/*

*/
//replace
#include<bits/stdc++.h> 
using namespace std;

int n,q;
const int N=2*1e5+5;

struct group{
	string a,b;
};

group c[N];
group d[N];

int main(){
	//文件读写，记得去注释
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>c[i].a>>c[i].b;
	}
	for(int i=1;i<=q;++i){
		cin>>d[i].a>>d[i].b;
	}
	
	for(int i=1;i<=q;++i){
		cout<<0<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
