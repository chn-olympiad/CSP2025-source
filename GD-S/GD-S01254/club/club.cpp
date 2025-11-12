#include<bits/stdc++.h>
using namespace std;
int ha[100005][3];
int ce[100005];
const int inf=100000000;
int mymax(int a,int b){
	return a>b?a:b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,T;
	cin>>T;
	int ans[10];
	int max,tent,check;
	int club[5];
	int ptr;
	int s;
	for(int i=1;i<=T;i++){
		cin>>n;
		tent=0;
		club[1]=club[2]=club[3]=0;
		for(int i=1;i<=n;i++){
			cin>>ha[i][0]>>ha[i][1]>>ha[i][2];
			max=ha[i][0];
			max=mymax(max,ha[i][1]);
			max=mymax(max,ha[i][2]);
			for(int j=0;j<3;j++){
				ha[i][j]-=max;
			}
			for(ptr=0;ptr<3;ptr++){
				if(ha[i][ptr]==0){
					ha[i][ptr]=-inf;
					break;
				}
			}
			tent+=max;
			club[ptr+1]++;
		}
		for(ptr=1;ptr<=3;ptr++){
			if(club[ptr]>n/2) break;
		}
		if(ptr<=3){
			s=0;
			for(int i=1;i<=n;i++){
				if(ha[i][ptr-1]==-inf){
					ce[s++]=mymax(ha[i][0],mymax(ha[i][1],ha[i][2]));
				}
			}
			sort(ce,ce+s);
			for(int i=1;i<=club[ptr]-n/2;i++){
				tent+=ce[s-i];
			}
		}
		ans[i]=tent;
	}
	for(int i=1;i<=T;i++){
		cout<<ans[i]<<endl;
	}
}
