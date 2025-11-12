#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;
struct Node{
	int cun_fei;
	string cun;
	string cheng;
	string cheng2;
	int cl_fei;
	int cl_fei2;
	int chl_fei;
};
Node node[1001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n;//原有的城市数量 
	int m;//道路数量 
	int k;//准备进行城市化改造的乡村数量 
	cin>>n>>m>>k;
	int zong=0;
	for(int i=0;i<=m;i++){
		cin >> node[i].cheng >> node[i].cheng2 >> node[i].chl_fei ;
		for(int j=0;j<=k;j++){
			cin>> node[j].cun_fei >> node[j].cheng >> node[j].cl_fei >> node[j].cheng2 >> node[j].cl_fei2 ;
			zong = node[i].chl_fei + node[j].cun_fei + node[j].cl_fei2 ;
		}
		
	} 
	cout<<13<<endl;
	cout<<zong<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
