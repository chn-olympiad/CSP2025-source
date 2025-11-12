#include <fstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int s[1000001];
//谢谢ccf的水题 
//ccf万岁 
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n; cin>>n>>m;//行数、列数 
	int lsfen; cin>>lsfen;//小s的分数 
	int wei=1;
	for(int i=2; i<=n*m; i++){
		cin>>s[i];
		if(s[i]>lsfen) wei++;
	}
	int flag=0;
	if(wei%n!=0)cout<<wei/n+1<<" "<<wei%n;
	else cout<<wei/n<<" "<<n;
	return 0;
}
