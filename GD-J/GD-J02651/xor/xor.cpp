#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
const int N=5e5+100;
using namespace std;

int n,k,num[N],l;

struct node{
	int x,y;
	node (){}
	node (int a,int b){x=a,y=b;}
	bool operator <(const node &a)const{
		if(y==a.y)return x<a.x;
		return y<a.y;
	}
}no[N];

map <int,vector<int> >m;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",num+i);
		num[i]^=num[i-1];
	}
	for(int i=1;i<=n;i++)m[num[i]].push_back(i);
	for(int i=0;i<=n;i++){
		int a=m[num[i]^k].size(),b;
		if(a){
			for(int j=0;j<a;j++){
				b=m[num[i]^k][j];
				if(b>i)no[++l]=node(i+1,b);
			}
		}
	}
	sort(no+1,no+l+1);
	int sum=0;
	for(int i=1,pos=-1;i<=l;i++){
		if(no[i].x>pos){
			pos=no[i].y;
			sum++;
		}
	}
	printf("%d\n",sum);
	return 0;
}
