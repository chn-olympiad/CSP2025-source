#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for (int l=0;l<t;l++){
		int a;
		cin>>a;
		int point[a][3];
		for (int x=0;x<a;x++){
			for (int y=0;y<3;y++){
				cin>>point[x][y];
			}
		}
		int fakeans=0,bigc[a],counter[3]={0,0,0};
		for (int x=0;x<a;x++){
			int big=0;
			for (int y=0;y<3;y++){
				if (point[x][y]>point[x][big]){
					big=y;
				}
				
			}
			 fakeans+=point[x][big];
				bigc[x]=big;
				counter[x]++;
				point[x][big]=0;//fang bian hou mian
		}
		if (max(counter[0],max(counter[1],counter[2]))<=a/2){
			cout<<fakeans<<endl;//jia zuo zhen
		}
		else{
			int cha[a];
			int over=0;
			for (int x=0;x<a;x++){
				if (counter[x]>a/2){
					over=x;
				}
			}
			for (int x=0;x<a;x++){
				cha[x]=0x3f3f3f3f;
			}
			for (int x=0;x<a;x++){
				for (int y=0;y<3;y++){
					if (bigc[x]==over)cha[x]=min(cha[x],point[x][bigc[x]]-point[x][y]);
				}
			}
			sort(cha,cha+sizeof(cha));
			for (int x=0;x<max(counter[0],max(counter[1],counter[2])-a/2);x++){
				fakeans-=cha[x];
			}
			cout<<fakeans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
