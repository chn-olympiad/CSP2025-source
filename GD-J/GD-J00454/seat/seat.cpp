#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[15][15];
struct nod{
	int s,num;//成绩和编号 
}v[120];
int cj;//R的成绩 
bool cmp(nod &x,nod &y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int all=n*m;
	for(int i=1;i<=all;i++){
		cin>>v[i].s;
		v[i].num=i;
	}
	sort(v+1,v+all+1,cmp);//成绩大到小 
	//输入并排序
	int i=1,j=1,x=1,init=1;//x控制转向 
	while(init<=all){//<=最后一个人也算 
		if(v[init].num==1){
			cout<<j<<' '<<i;//几列几行 
			return 0;
		}
		if(i>=n&&x==1){
			x=-1;
			j++;//此列填满 
		}else if(i<=1&&x==-1){
			x=1;
			j++;//此列填满 
		}
		else i+=x;//不能删else否则判断时连走两个 
		init++;
	}//坐下，编号计入a,如发现R的位置，直接输出 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
