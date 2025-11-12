#include <bits/stdc++.h>
using namespace std;
struct cl{
	int a;
	int b;
	int c;
};
struct pd{
	int v;//数值
	bool yes=1;//是否启用
	int num;//是第几个
	int ber;//哪个社团
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		pd m[50000];
		int h=0;
		for(int j=0;j<n;j++){
			cin>>m[h].v;
			m[h].num=j;
			m[h].ber=0;
			h++;
			cin>>m[h].v;
			m[h].num=j;
			m[h].ber=1;
			h++;
			cin>>m[h].v;
			m[h].num=j;
			m[h].ber=2;
			h++;
		}
		int v=0;
		for(int j=0;j<h;j++){
			for(int l=0;l<h-1;l++){
				if(m[l].v<m[l+1].v){
					swap(m[l],m[l+1]);
				}
			}
		}
		int nn[3]={0,0,0};
		for(int j=0;j<n;j++){
			for(int l=0;l<h;l++){
				if(nn[0]==n/2){
					for(int y=0;y<h;y++){
						if(m[y].ber==0){
							m[y].yes=0;
						}
					}
				}
				if(nn[1]==n/2){
					for(int y=0;y<h;y++){
						if(m[y].ber==1){
							m[y].yes=0;
						}
					}
				}
				if(nn[2]==n/2){
					for(int y=0;y<h;y++){
						if(m[y].ber==2){
							m[y].yes=0;
						}
					}
				}
				if(m[l].yes){
					v+=m[l].v;
					for(int y=0;y<h;y++){
						if(m[y].num==m[l].num){
							m[y].yes=0;
						}
					}
					nn[m[l].ber]+=1;
					break;
				}
			}
		}
		cout<<v;
		cout<<endl;
	}
	return 0;
}