#include<bits/stdc++.h>
using namespace std;

int a[500];
int b[30][30];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int num=n*m-1;
	int id=1;
	int mid;
	cin>>mid;
	a[0]=mid;
	while(num--){
		int sore;
		scanf("%d",&sore);
		a[id]=sore;
		id++;
	}
	sort(a,a+id,cmp);
	num=n*m;
	int idx=1,idy=1;
	int i=0;
	int zhi=1;
	while(num--){
		if(a[i]==mid){
			break;
		}
		b[idx][idy]=a[i];
		idx+=zhi;
		i++;
		if(idx==n+1||idx==0){
			idy++;
			if(idx==n+1){
				idx--;
			}else{
				idx++;
			}
			zhi*=-1;
		}
	}
	cout<<idy<<" "<<idx;
	return 0;
} 
